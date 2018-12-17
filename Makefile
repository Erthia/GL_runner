CC = g++
CFLAGS = -Wall -O2 -g
LDFLAGS = -lSDL -lSDL2 -lGLU -lglut -lGL -lGLEW -lm -lSDL2_image -lSDL_mixer

APP_BIN = glrunner
SRC_PATH = src
OBJ_PATH = obj
INC_PATH = $(addprefix -I,$(shell find ./include -type d -print))
BIN_PATH = bin
LIB_PATH = lib

SRC_FILES = $(shell find $(SRC_PATH) -type f -name '*.cpp')
OBJ_FILES = $(patsubst $(SRC_PATH)/%.cpp,$(OBJ_PATH)/%.o, $(SRC_FILES))

all: $(APP_BIN)

$(APP_BIN): $(OBJ_FILES)
	@mkdir -p $(BIN_PATH)
	$(CC) -o $(BIN_PATH)/$(APP_BIN) $(OBJ_FILES) $(LDFLAGS)

$(OBJ_PATH)/%.o: $(SRC_PATH)/%.cpp
	@mkdir -p "$(@D)"
	$(CC) -c $< -o $@ $(CFLAGS) $(INC_PATH)

clean:
	rm $(OBJ_FILES) $(BIN_PATH)/$(APP_BIN)
