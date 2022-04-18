CXX = g++
OPTIONS = -Wall
PROGRAM = main.exe
SRC = Card.cpp Deck.cpp Hand.cpp
HEADERS = $(patsubst %.cpp, %.h, $(SRC)) Player.h

all: $(PROGRAM)

$(PROGRAM): $(HEADERS) $(SRC) $(patsubst %.exe, %.cpp, $(PROGRAM))
	$(CXX) $(OPTIONS) $(filter-out $(HEADERS), $^) -o $@

run: $(PROGRAM)
	./$(PROGRAM)

cleanL:
	rm -f $(PROGRAM)

clean:
	del *.exe *.o *.out
