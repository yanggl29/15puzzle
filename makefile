CC = g++

all:E02_15puzzle
E02_15puzzle:15puzzle.o ida_star.o
	@$(CC) -lm $^ -o $@
15puzzle.o:15puzzle.cpp
	@$(CC) -lm $^ -c -o $@
heuristic.o:ida_star.cpp
	@$(CC) -lm $^ -c -o $@
clean:
	@rm *.o
	@rm E02_15puzzle