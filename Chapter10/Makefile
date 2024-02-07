COMPILE.C=$(COMPILE.cc)
COMPILE.cc=$(CXX) $(CXXFLAGS) $(CPPFLAGS) $(TARGET_ARCH) -c
CXXFLAGS=-g3 -I headers 
CPPFLAGS= -Wall -Wextra -Wpedantic 
CXX= g++
OUTPUT_OPTION = -o $@
#Linking:
LINK.o = $(CC) $(LDFLAGS) $(TARGET_ARCH)
CC= g++

vpath %.cc sources
vpath %.h headers

#rules:
%: %.o 
	$(LINK.o) $(OUTPUT_OPTION) $<
%.o: %.c++
	$(COMPILE.C) $(OUTPUT_OPTION) $<

run: c++
	./c++
#Linking:
c++: c++.o stock.o
#Compiling:
stock.o:c++.h
c++.o:c++.h
#The compiler while compiling the file above needs to know about the existence of implementations
#in the file stock10.o, so we have to include it in the c++.c file

.PHONY: depend #Now the file will be updated each time it is called.
depend: c++.cc
	g++ -I headers -M $(CPPFLAGS) $^ > $@
	more depend

.PHONY:clean
clean:
	rm -rf *.o c++