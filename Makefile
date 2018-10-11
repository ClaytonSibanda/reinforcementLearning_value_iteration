FLAGS= -g  -std=c++11 -o
CC=g++

main:main.cpp  state.h
	$(CC) $(FLAGS) $@ $^

run:
	./main
clean:
	rm -f ann
