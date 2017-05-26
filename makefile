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
	INCLUDES= H:\SDL2-2.0.5\include -I H:\SDL2_ttf-2.0.14\include -I H:\SDL2_image-2.0.1\include -I H:\SDL2_mixer-2.0.1\include
else
	OUTPUT=$(NAME)
	INCLUDES= /usr/include/SDL2
endif

ifeq ($(OS_Detected), Windows)
	LIBDIRS= H:\SDL2-2.0.5\lib\x86 -L H:\SDL2_ttf-2.0.14\lib\x86 -L H:\SDL2_image-2.0.1\lib\x86 -L H:\SDL2_mixer-2.0.1\lib\x86
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
