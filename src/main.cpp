#include <glimac/SDLWindowManager.hpp>
#include <GL/glew.h>
#include <iostream>
#include <glimac/common.hpp>
#include <glimac/Sphere.hpp>
#include <glimac/cube.hpp>
#include <glimac/Object.hpp>
#include <glimac/Program.hpp>
#include "TrackballCamera.hpp"
#include <glimac/FilePath.hpp>
#include <glimac/Image.hpp>
#include <glimac/Landmark.hpp>
#include <glimac/Grid.hpp>
#include <glm/glm.hpp>
#include <glm/gtc/random.hpp>
#include <vector>
#include <cstdlib>
#include <GLFW/glfw3.h>
#include <fstream>


//#include <utils.cpp>


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
    TrackballCamera camera(0,0,0);


    // Initialize glew for OpenGL3+ support
    GLenum glewInitError = glewInit();
    if(GLEW_OK != glewInitError) {
        std::cerr << glewGetErrorString(glewInitError) << std::endl;
        return EXIT_FAILURE;
    }

    FilePath applicationPath(argv[0]);
    Program program = loadProgram("./shaders/3d.vs.glsl",
                                  "./shaders/normals.fs.glsl" );
    program.use();


    std::cout << "OpenGL Version : " << glGetString(GL_VERSION) << std::endl;
    std::cout << "GLEW Version : " << glewGetString(GLEW_VERSION) << std::endl;


    /*********************************
     * HERE SHOULD COME THE INITIALIZATION CODE
     *********************************/

    GLint uModelMVMatrix = glGetUniformLocation(program.getGLId(), "uMVMatrix");
    GLint uModelMVPMatrix = glGetUniformLocation(program.getGLId(), "uMVPMatrix");
    GLint uNormalMatrix = glGetUniformLocation(program.getGLId(), "uNormalMatrix");

    glEnable(GL_DEPTH_TEST);

    GLuint vbo[3];
    GLuint vao[3];
    //  Cube
    Cube cube;
    cube.vboManager(vbo[0]);
    cube.vaoManager(vao[0],vbo[0]);
    // Landmark
    Landmark landmark;
    landmark.vboManager(vbo[1]);
    landmark.vaoManager(vao[1],vbo[1]);
    // Grid
    Grid grid;
    grid.vboManager(vbo[2]);
    grid.vaoManager(vao[2],vbo[2]);




    glm::mat4 projMatrix,MVMatrix,NormalMatrix;

    // Application loop:

    bool done = false;
    while(!done) {
        // Event loop:
        SDL_Event e;
        while(windowManager.pollEvent(e)) {

          if (e.type == SDL_KEYDOWN)
            camera.onKeyboardEvent(e);

          if (e.button.button == SDL_BUTTON_WHEELUP || e.button.button == SDL_BUTTON_WHEELDOWN )
            camera.onMouseWheelEvent(e);


          if (windowManager.isMouseButtonPressed(SDL_BUTTON_LEFT))
          {
            camera.onMouseEvent(e);
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

        glBindVertexArray(vao[0]);
          glDrawArrays(GL_TRIANGLES,0,cube.getVertexCount());
        glBindVertexArray(0);


        glBindVertexArray(vao[1]);
            glDrawArrays(GL_LINES,0,landmark.getVertexCount());
        glBindVertexArray(0);

        glBindVertexArray(vao[2]);
            glDrawArrays(GL_LINES,0,grid.getVertexCount());
        glBindVertexArray(0);





        // Update the display
        windowManager.swapBuffers();
    }



    return EXIT_SUCCESS;
}
