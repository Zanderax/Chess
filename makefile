CXX      := -g++
CXXFLAGS := -Wall -Wextra -Werror -O3 -Wno-unused-variable -Wno-unused-result -std=c++17 -Wfatal-errors
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
