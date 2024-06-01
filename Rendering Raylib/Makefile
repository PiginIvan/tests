.PHONY: all clean

PROJECT_NAME       ?= main
#RAYLIB_VERSION     ?= 4.2.0
RAYLIB_PATH        ?= C:/raylib/raylib
COMPILER_PATH      ?= C:/raylib/w64devkit/bin
PLATFORM           ?= PLATFORM_DESKTOP
#RAYLIB_LIBTYPE     ?= STATIC
#BUILD_MODE         ?= RELEASE
PLATFORM_OS=WINDOWS
export PATH := $(COMPILER_PATH):$(PATH)

#RAYLIB_RELEASE_PATH 	?= $(RAYLIB_PATH)/src
CXX = g++
MAKE = mingw32-make

CFLAGS += -std=c++20
CFLAGS += -Wl,--subsystem,windows

INCLUDE_PATHS = -I. -I$(RAYLIB_PATH)/src -I$(RAYLIB_PATH)/src/external -Iinclude
LDFLAGS = -L. -L$(RAYLIB_RELEASE_PATH) -L$(RAYLIB_PATH)/src
LDLIBS = -lraylib -lopengl32 -lgdi32 -lwinmm 

SRC_DIR = src
OBJ_DIR = obj
OBJS ?= src/main.cpp src/Fps.cpp src/Tools.cpp src/World.cpp src/Map.cpp src/Player.cpp

all:
	$(MAKE) $(PROJECT_NAME)

$(PROJECT_NAME): $(OBJS)
	$(CXX) -o $(PROJECT_NAME)$(EXT) $(OBJS) $(CFLAGS) $(INCLUDE_PATHS) $(LDFLAGS) $(LDLIBS) -D$(PLATFORM)

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.cpp
	$(CXX) -c $< -o $@ $(CFLAGS) $(INCLUDE_PATHS) -D$(PLATFORM)

clean:
ifeq ($(PLATFORM),PLATFORM_DESKTOP)
    ifeq ($(PLATFORM_OS),WINDOWS)
		del *.o *.exe /s
    endif
endif
ifeq ($(PLATFORM),PLATFORM_WEB)
	del *.o *.html *.js
endif
	@echo Cleaning done
