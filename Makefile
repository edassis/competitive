FILE := main.cpp
OUT_FILE := a

CXX := g++-11

# COMP_ARGS := -fsanitize=address -std=c++17 -Wall -Wextra -g
COMP_ARGS := -std=c++17 -Wall -Wextra -g

.PONY: all compile exec clear

all: compile

compile:
	$(CXX) $(COMP_ARGS) $(FILE) -o $(OUT_FILE)

exec: compile
	./$(OUT_FILE)

clear:
	rm $(OUT_FILE)
