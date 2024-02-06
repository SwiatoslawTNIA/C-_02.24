run: cpp
	./cpp
#Linking:
cpp: main.o sub.o
	g++ -o $@ $^ 
main.o: main.cc h.h
	g++ -c -g3 -o $@ -Wall -Wextra -Wpedantic $<
sub.o: sub.cc h.h
	g++ -c -g3 -o $@ -Wall -Wextra -Wpedantic $<