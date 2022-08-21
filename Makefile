FILE := lib/seg.cpp
OUT_FILE := a

CXX := g++

COMP_ARGS := -std=c++17 -Wall -Wno-unused-result -g 
EXTENDED_ARGS := -Wshadow -fsanatize-=address -fsanitize=undefined -D_GLIBCXX_DEBUG

.PONY: all compile exec clear compilex

all: compile

compile:
	$(CXX) $(COMP_ARGS) $(FILE) -o $(OUT_FILE)

compilex:
	$(CXX) $(COMP_ARGS) $(EXTENDED_ARGS) $(FILE) -o $(OUT_FILE)
	
exec: compile
	./$(OUT_FILE)

clear:
	rm $(OUT_FILE)
