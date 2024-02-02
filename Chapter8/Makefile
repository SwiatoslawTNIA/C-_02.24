VPATH = sources headers
run: cpp
	./cpp 

cpp: cpp.o cc.h
	g++ -I headers -o $@ $< -Wall -Wextra -Wpedantic

cpp.o: c.cpp cc.h
	g++ -I headers -c -o $@ $< -Wall -Wextra -Wpedantic	

.PHONY: clean
clean: 
	rm -f cpp *.o