NAME=test

ifeq ($(OS), Windows_NT)
	OS_Detected := Windows
else
	OS_Detected := Linux
endif

CC=g++
FLAGS= -g -std=c++0x -Wall

ifeq ($(OS_Detected), Windows)
	OUTPUT=$(NAME).exe
	INCLUDES= include\SDL2_include -I include\SDL2_ttf_include -I include\SDL2_image_include -I include\SDL2_mixer_include
else
	OUTPUT=$(NAME)
	INCLUDES= /usr/include/SDL2
endif

ifeq ($(OS_Detected), Windows)
	LIBDIRS= lib\SDL2_lib_x86 -L lib\SDL2_ttf_lib_x86 -L lib\SDL2_image_lib_x86 -L lib\SDL2_mixer_lib_x86
	LIBS= SDL2 -lSDL2_ttf -lSDL2_image -lSDL2_mixer
	LIB= -L $(LIBDIRS) -l$(LIBS)
else
	LIB= -lSDL2 -lSDL2_ttf -lSDL2_image -lSDL2_mixer
endif

CPP_FILES := $(wildcard src/*.cpp)
OBJ_FILES := $(addprefix obj/,$(notdir $(CPP_FILES:.cpp=.o)))

ifeq ($(OS_Detected), Windows)
	OS_Build := $(NAME)_win.exe
else
	OS_Build := $(NAME)_linux
endif

COPY := cp -rf $(OUTPUT) build/$(OS_Build)

$(OS_Build): $(NAME)
	$(COPY)

$(NAME): $(OBJ_FILES)
	$(CC) $(FLAGS) -o $@ $^ $(LIB)

obj/%.o: src/%.cpp
	$(CC) $(FLAGS) -c -I $(INCLUDES) -o $@ $<

.PHONY : clean
clean:
	-rm $(OUTPUT) $(OBJ_FILES)

run: $(NAME)
	./$(NAME)
