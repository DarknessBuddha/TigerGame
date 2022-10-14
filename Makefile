CXX = g++
OPTIONS = -Wall
PROGRAM = main.out
SRC = Card.cpp Deck.cpp Hand.cpp
HEADERS = $(patsubst %.cpp, %.h, $(SRC)) Player.h

all: $(PROGRAM)

$(PROGRAM): $(HEADERS) $(SRC) $(patsubst %.out, %.cpp, $(PROGRAM))
	$(CXX) $(OPTIONS) $(filter-out $(HEADERS), $^) -o $@

run: $(PROGRAM)
	./$(PROGRAM)

clean:
	rm -f $(PROGRAM)

