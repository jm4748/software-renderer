SRC_DIR = source/
INC_DIR = $(SRC_DIR)include/

BLD_DIR = build/
OBJ_DIR = $(BLD_DIR)obj/
BIN_DIR = $(BLD_DIR)bin/

SDL_COMP = $(shell sdl2-config --cflags)
SDL_LINK = $(shell sdl2-config --libs)

PRG_NAME = program
PRG_SRCS = system.cpp     \
           main_state.cpp \
           main.cpp
PRG_COMP = -std=c++17 $(SDL_COMP)
PRG_LINK = $(SDL_LINK)

