FILE := src/main.cpp
OUT_FILE := a

# https://stackoverflow.com/a/14777895/8903027
ifeq '$(findstring ;,$(PATH))' ';'
    detected_OS := Windows
else
    detected_OS := $(shell uname 2>/dev/null || echo Unknown)
    detected_OS := $(patsubst CYGWIN%,Cygwin,$(detected_OS))
    detected_OS := $(patsubst MSYS%,MSYS,$(detected_OS))
    detected_OS := $(patsubst MINGW%,MSYS,$(detected_OS))
endif

ifeq ($(detected_OS), Darwin)
	CXX := g++-12
else
	CXX := g++
endif

# COMP_ARGS := -fsanitize=address -std=c++17 -Wall -Wextra -g
COMP_ARGS := -std=c++17 -Wall -Wextra -g -I.

.PONY: all compile exec clean

all: compile

compile:
	$(CXX) $(COMP_ARGS) $(FILE) -o $(OUT_FILE)

exec: compile
	./$(OUT_FILE)

clean:
	rm -r $(OUT_FILE) build/ .cache/
