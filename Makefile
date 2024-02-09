
COMP_ARGS := -std=c++20 -Wall -Wno-unused-result -ggdb -D_GLIBCXX_DEBUG -D_GLIBCXX_DEBUG_PEDANTIC
EXTENDED_ARGS := -Wshadow -fsanitize=address -fsanitize=undefined

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
	# CXX := $(shell compgen -c | grep -E "^g\+\+-\d+" -m1)
	CXX := clang++

	# COMP_ARGS += --sysroot=$(shell xcrun --show-sdk-path)
	# COMP_ARGS := -std=c++20 -Iinclude -Wall -g
	# EXTENDED_ARGS := -Wshadow -D_GLIBCXX_DEBUG
	# g++ $(DIR)/$(FILE).cpp -o $(FILE) -I. -std=c++20 -g
	
	# g++ > 11 é bugado no mac, não dá para criar arrays > 1e3.
	COMP_ARGS := -stdlib=libstdc++ \
		-stdlib++-isystem /opt/homebrew/Cellar/gcc@11/11.4.0/include/c++/11 \
		-cxx-isystem /opt/homebrew/Cellar/gcc@11/11.4.0/include/c++/11/aarch64-apple-darwin22 \
		-L /opt/homebrew/Cellar/gcc@11/11.4.0/lib/gcc/11 \
		$(COMP_ARGS)
else
	CXX := g++
endif

FILE := src/main.cpp

.PONY: all compile sanz exec clean
# .SILENT:

compile:
	$(CXX) $(COMP_ARGS) $(FILE) -o $(FILE:.cpp=)

sanz:
	$(CXX) $(COMP_ARGS) $(EXTENDED_ARGS) $(FILE) -o $(FILE:.cpp=)
	
exec: compile
	./$(FILE)

clean:
	rm -rf $(FILE) build/ .cache/

#########

SRC_DIR := src

SRCS := $(wildcard $(SRC_DIR)/*.cpp)

BINS := $(SRCS:$(SRC_DIR)/%.cpp=$(SRC_DIR)/%)

# $(info The value of SRCS is $(SRCS))

# $(info The value of SRCS is $(BINS))

all: $(BINS)

$(SRC_DIR)/%: $(SRC_DIR)/%.cpp
	$(CXX) $(COMP_ARGS) $< -o $@
