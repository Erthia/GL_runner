#include <glimac/SDLWindowManager.hpp>
#include <GL/glew.h>
#include <iostream>
#include <glimac/common.hpp>
#include <glimac/Sphere.hpp>
#include <glimac/cube.hpp>
#include <glimac/Program.hpp>
#include <glimac/TrackballCamera.hpp>
#include <glimac/FilePath.hpp>
#include <glimac/Image.hpp>
#include <glm/glm.hpp>
#include <glm/gtc/random.hpp>
#include <vector>
#include <cstdlib>
#include <GLFW/glfw3.h>
#include <fstream>


using namespace glimac;

std::string readFile(const char *filePath) {
    std::string content;
    std::ifstream fileStream(filePath, std::ios::in);

    if(!fileStream.is_open()) {
        std::cerr << "Could not read file " << filePath << ". File does not exist." << std::endl;
        return "";
    }

    std::string line = "";
    while(!fileStream.eof()) {
        std::getline(fileStream, line);
        content.append(line + "\n");
    }

    fileStream.close();
    return content;
}

GLuint LoadShader(const char *vertex_path, const char *fragment_path) {
    GLuint vertShader = glCreateShader(GL_VERTEX_SHADER);
    GLuint fragShader = glCreateShader(GL_FRAGMENT_SHADER);

    // Read shaders
    std::string vertShaderStr = readFile(vertex_path);
    std::string fragShaderStr = readFile(fragment_path);
    const char *vertShaderSrc = vertShaderStr.c_str();
    const char *fragShaderSrc = fragShaderStr.c_str();

    GLint result = GL_FALSE;
    int logLength;


    // Compile vertex shader
    std::cout << "Compiling vertex shader." << std::endl;
    glShaderSource(vertShader, 1, &vertShaderSrc, NULL);
    glCompileShader(vertShader);

    // Check vertex shader
    glGetShaderiv(vertShader, GL_COMPILE_STATUS, &result);
    glGetShaderiv(vertShader, GL_INFO_LOG_LENGTH, &logLength);
    std::vector<char> vertShaderError((logLength > 1) ? logLength : 1);
    glGetShaderInfoLog(vertShader, logLength, NULL, &vertShaderError[0]);
    std::cout << &vertShaderError[0] << std::endl;

    // Compile fragment shader
    std::cout << "Compiling fragment shader." << std::endl;
    glShaderSource(fragShader, 1, &fragShaderSrc, NULL);
    glCompileShader(fragShader);

    // Check fragment shader
    glGetShaderiv(fragShader, GL_COMPILE_STATUS, &result);
    glGetShaderiv(fragShader, GL_INFO_LOG_LENGTH, &logLength);
    std::vector<char> fragShaderError((logLength > 1) ? logLength : 1);
    glGetShaderInfoLog(fragShader, logLength, NULL, &fragShaderError[0]);
    std::cout << &fragShaderError[0] << std::endl;

    std::cout << "Linking program" << std::endl;
    GLuint program = glCreateProgram();
    glAttachShader(program, vertShader);
    glAttachShader(program, fragShader);

    glBindAttribLocation(program, 3, "aVertexPosition");
    glBindAttribLocation(program, 8, "aVertexColor");

    glLinkProgram(program);

    glGetProgramiv(program, GL_LINK_STATUS, &result);
    glGetProgramiv(program, GL_INFO_LOG_LENGTH, &logLength);
    std::vector<char> programError( (logLength > 1) ? logLength : 1 );
    glGetProgramInfoLog(program, logLength, NULL, &programError[0]);
    std::cout << &programError[0] << std::endl;

    glDeleteShader(vertShader);
    glDeleteShader(fragShader);

    return program;
}
/********************************
END - IF YOU'RE USING GLSL VERSION 130
********************************/

int main(int argc, char** argv) {




    // Initialize SDL and open a window
    int width = 800;
    int height =600;
    SDLWindowManager windowManager(800, 600, "GLImac");
    TrackballCamera camera(5,0,0);


    // Initialize glew for OpenGL3+ support
    GLenum glewInitError = glewInit();
    if(GLEW_OK != glewInitError) {
        std::cerr << glewGetErrorString(glewInitError) << std::endl;
        return EXIT_FAILURE;
    }

    FilePath applicationPath(argv[0]);
    std::cout<<applicationPath.dirPath()<<std::endl;
    Program program = loadProgram("./shaders/3d.vs.glsl",
                                  "./shaders/normals.fs.glsl" );
    program.use();

     /********************************
    IF YOU'RE USING GLSL VERSION 130
    DELETE THIS PART IF YOU'RE VERSION 330
    ********************************/

    /********************************
    END - IF YOU'RE USING GLSL VERSION 130
    ********************************/


    std::cout << "OpenGL Version : " << glGetString(GL_VERSION) << std::endl;
    std::cout << "GLEW Version : " << glewGetString(GLEW_VERSION) << std::endl;


    /*********************************
     * HERE SHOULD COME THE INITIALIZATION CODE
     *********************************/

    GLint uModelMVMatrix = glGetUniformLocation(program.getGLId(), "uMVMatrix");
    GLint uModelMVPMatrix = glGetUniformLocation(program.getGLId(), "uMVPMatrix");
    GLint uNormalMatrix = glGetUniformLocation(program.getGLId(), "uNormalMatrix");
    //GLint uModelTexture = glGetUniformLocation(program.getGLId(),"uTexture");


    glEnable(GL_DEPTH_TEST);

    GLuint vbo;
    glGenBuffers(1,&vbo);
    glBindBuffer(GL_ARRAY_BUFFER,vbo);

    Cube cube(5);
    int nbVertice = cube.getVertexCount();

    glBufferData(GL_ARRAY_BUFFER,nbVertice*sizeof(ShapeVertex),cube.getDataPointer(), GL_STATIC_DRAW);
    glBindBuffer(GL_ARRAY_BUFFER,0);

    GLuint vao;
    glGenVertexArrays(1,&vao);
    glBindVertexArray(vao);
    glEnableVertexAttribArray(0);
    glEnableVertexAttribArray(1);
    glEnableVertexAttribArray(2);
     // Spécification des attribut de vertex


    glBindBuffer(GL_ARRAY_BUFFER,vbo);
    glVertexAttribPointer(0,3,GL_FLOAT,GL_FALSE,sizeof(ShapeVertex),(void *) offsetof(ShapeVertex,position));
    glVertexAttribPointer(1,3,GL_FLOAT,GL_FALSE,sizeof(ShapeVertex),(void *) offsetof(ShapeVertex,normal));
    glVertexAttribPointer(2,2,GL_FLOAT,GL_FALSE,sizeof(ShapeVertex),(void *) offsetof(ShapeVertex,texCoords));
    glBindBuffer(GL_ARRAY_BUFFER,0);
    glBindVertexArray(0);

    glm::mat4 projMatrix,MVMatrix,NormalMatrix;

    if (cube.getDataPointer() == NULL)
    {
        std::cout<<"ptr NULL"<<std::endl;
    }

    // Application loop:

    std::cout<< "Vertex Count :" <<cube.getVertexCount()<<std::endl;
    bool done = false;
    while(!done) {
        // Event loop:
        SDL_Event e;
        while(windowManager.pollEvent(e)) {

            if (windowManager.isMouseButtonPressed(SDL_BUTTON_LEFT))
            {
                glm::ivec2 mousePosition = windowManager.getMousePosition();
                //std::cout<<mousePosition<<std::endl;

                if (mousePosition.y>width/2)
                    camera.moveFront(0.01);

                if (mousePosition.y<width/2)
                    camera.moveFront(-0.01);

            }

            if (windowManager.isMouseButtonPressed(SDL_BUTTON_RIGHT))
            {
                glm::ivec2 mousePosition = windowManager.getMousePosition();
                //std::cout<<mousePosition<<std::endl;

                if (mousePosition.x>width/2)
                    //std::cout<<"SUPERIEUR"<<std::endl;
                    camera.rotateLeft(1);
                if (mousePosition.x<width/2)
                    //std::cout<<"SUPERIEUR"<<std::endl;
                    camera.rotateLeft(-1);
                if (mousePosition.y>height/2)
                    camera.rotateUp(1);
                if (mousePosition.y<height/2)
                    camera.rotateUp(-1);

            }


            if(e.type == SDL_QUIT) {
                done = true; // Leave the loop after this iteration
            }
        }

        /*********************************
         * HERE SHOULD COME THE RENDERING CODE
         *********************************/
        glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

        float a = 800.0/600.0;

        projMatrix = glm::perspective(glm::radians(70.f),a,0.1f,100.f)*camera.getViewMatrix();
        MVMatrix = glm::translate(glm::mat4(1.0),glm::vec3(0.0,0.0,-5.0))*camera.getViewMatrix();
        NormalMatrix = glm::transpose(glm::inverse(MVMatrix));
        glm::mat4 mat1 = projMatrix * MVMatrix;
        glUniformMatrix4fv(uModelMVPMatrix,1,GL_FALSE,glm::value_ptr(mat1));
        glUniformMatrix4fv(uModelMVMatrix,1,GL_FALSE,glm::value_ptr(MVMatrix));
        glUniformMatrix4fv(uNormalMatrix,1,GL_FALSE,glm::value_ptr(NormalMatrix));

        glBindVertexArray(vao);
            glDrawArrays(GL_TRIANGLES,0,cube.getVertexCount());
        glBindVertexArray(0);


        // Update the display
        windowManager.swapBuffers();
    }



    return EXIT_SUCCESS;
}
