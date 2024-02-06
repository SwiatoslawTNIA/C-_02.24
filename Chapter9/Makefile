COMPILE.C=$(COMPILE.cc)
COMPILE.cc=$(CXX) $(CXXFLAGS) $(CPPFLAGS) $(TARGET_ARCH) -c
CXXFLAGS=-g3 -I headers 
CPPFLAGS= -Wall -Wextra -Wpedantic 
CXX= g++
OUTPUT_OPTION= -o $@

HEADS=c++.h namespaces.h
#Linking:
LINK.o=$(CC) $(LDFLAGS) $(TARGET_ARCH)
CC=g++

vpath %.cc sources
vpath %.h headers

#rules:
%: %.o 
	$(LINK.o) $(OUTPUT_OPTION) $^
%.o: %.c++
	$(COMPILE.C) $(OUTPUT_OPTION) $<

run: c++
	./c++

c++: c++.o c1++.o
c++.o:$(HEADS)
c1++.o:$(HEADS) 

.PHONY:clean

clean:
	rm -rf *.o c++