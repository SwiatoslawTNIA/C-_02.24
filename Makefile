run: cpp
	 valgrind ./cpp 

cpp: cpp.o
	g++ -o cpp cpp.o -Wall -Wextra -Wpedantic

cpp.o: c.cpp
	g++ -c -o cpp.o c.cpp -Wall -Wextra -Wpedantic	
clean: 
	rm -f cpp cpp.o