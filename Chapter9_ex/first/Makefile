#Link:
.PHONY: run
run: main
	valgrind ./main
main: l.o main.o
	g++ -o $@ $^
#Compile:
l.o: pe9-1.cpp golf.h
	g++ -c -g3 -o $@ -Wall -Wextra -Wpedantic $<
main.o: main.cc golf.h
	g++ -c -g3 -o $@ -Wall -Wextra -Wpedantic $<
