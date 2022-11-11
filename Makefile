FILE := main.cpp
DIR := src
OUT_FILE := a

COMP_ARGS := -std=c++17 -Wall -Wno-unused-result -g 
EXTENDED_ARGS := -Wshadow -fsanitize=address -fsanitize=undefined -D_GLIBCXX_DEBUG

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
	CXX := c++
	COMP_ARGS += -I.
else
	CXX := g++
endif

.PONY: all compile exec clean debug

all: compile

compile:
	$(CXX) $(COMP_ARGS) $(DIR)/$(FILE) -o $(OUT_FILE)

debug:
	$(CXX) $(COMP_ARGS) $(EXTENDED_ARGS) $(DIR)/$(FILE) -o $(OUT_FILE)
	
exec: compile
	./$(OUT_FILE)

clean:
	rm -r $(OUT_FILE) build/ .cache/
