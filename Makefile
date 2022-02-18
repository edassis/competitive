FILE := main.cpp
OUT_FILE := a

CXX := g++

# COMP_ARGS := -fsanitize=address -std=c++17 -Wall -Wextra -g
COMP_ARGS := -std=c++17 -Wall -Wextra -g -I"."

.PONY: all compile exec

all: compile

compile:
	$(CXX) $(COMP_ARGS) $(FILE) -o $(OUT_FILE)

exec: compile
	./$(OUT_FILE)

clear:
	rm $(OUT_FILE)
