CXX      := -g++
CXXFLAGS := -Wall -Wextra -Werror -std=c++11 -O3 -Wno-unused-variable -Wno-unused-result -Wfatal-errors
LDFLAGS  := -L/usr/lib -lstdc++ -lm 
BUILD    := build
OBJ_DIR  := $(BUILD)/objects
APP_DIR  := $(BUILD)/apps
TARGET   := chess
INCLUDE  := -Iinclude/
SRC      :=                      \
	      $(wildcard src/*.cpp) 

OBJECTS := $(SRC:%.cpp=$(OBJ_DIR)/%.o)

all: build $(APP_DIR)/$(TARGET)

test:
	cd testing && $(MAKE)

$(OBJ_DIR)/%.o: %.cpp
	   @mkdir -p $(@D)
	      $(CXX) $(CXXFLAGS) $(INCLUDE) -o $@ -c $<

$(APP_DIR)/$(TARGET): $(OBJECTS)
	   @mkdir -p $(@D)
	      $(CXX) $(CXXFLAGS) $(INCLUDE) $(LDFLAGS) -o $(APP_DIR)/$(TARGET) $(OBJECTS)

.PHONY: all build clean

build:
	   @mkdir -p $(APP_DIR)
	      @mkdir -p $(OBJ_DIR)

clean:
	   rm -rf build/*
