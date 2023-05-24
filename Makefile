FILE := main.cpp
DIR := src
OUT_FILE := a

COMP_ARGS := -std=c++17 -Wall -Wno-unused-result -Og

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
	CXX := $(shell compgen -c | grep g++ -m1)
	# CXX := clang++

	# COMP_ARGS += --sysroot=$(shell xcrun --show-sdk-path)
	# COMP_ARGS := -std=c++17 -Iinclude -Wall -Og
	
	EXTENDED_ARGS := -Wshadow -D_GLIBCXX_DEBUG

	# g++ $(DIR)/$(FILE) -o $(OUT_FILE) -I. -std=c++17 -Og
	
	CMP_CMD := clang++ -stdlib=libstdc++ \
		-stdlib++-isystem /opt/homebrew/Cellar/gcc/13.1.0/include/c++/13 \
		-cxx-isystem /opt/homebrew/Cellar/gcc/13.1.0/include/c++/13/aarch64-apple-darwin22 \
		-L /opt/homebrew/Cellar/gcc/13.1.0/lib/gcc/13 \
		-std=c++17 \
		-o $(OUT_FILE) $(DIR)/$(FILE)

else
	CXX := g++
	EXTENDED_ARGS := -Wshadow -fsanitize=address -fsanitize=undefined -D_GLIBCXX_DEBUG
endif

.PONY: all compile exec clean debug mac
# .SILENT: mac

all: compile

compile:
	$(CXX) $(COMP_ARGS) $(DIR)/$(FILE) -o $(OUT_FILE)

mac:
	$(CMP_CMD)

debug:
	$(CXX) $(COMP_ARGS) $(EXTENDED_ARGS) $(DIR)/$(FILE) -o $(OUT_FILE)
	
exec: compile
	./$(OUT_FILE)

clean:
	rm -rf $(OUT_FILE) build/ .cache/
