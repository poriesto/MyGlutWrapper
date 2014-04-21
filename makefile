CC=clang++
CFLAGS=-std=c++11 -Wall -o3 -g -Weverything
LIBS=-lGL -lGLU -lglut
INC_PATH=/usr/include/GL

BUILD_DIR  := 
SOURCE_DIR := 

OBJ :=  $(BUILD_DIR)GLWindow.o\
   	$(BUILD_DIR)test.o
BIN := main

$(BUILD_DIR)/%.o: $(SOURCE_DIR)/%.cpp
	$(CC) -c $(CFLAGS) $< -o $@

all: $(BIN)
$(BIN): $(OBJ)
	$(CC) -o $(BUILD_DIR)$(BIN) $(OBJ) $(LIBS)
clean:
	rm -f $(OBJ) $(BIN)
