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

.PHONY: run
run: c++
	./c++

c++: c++.o bankAccount.o person.o plorg.o
c++.o:c++.h
bankAccount.o:c++.h
person.o:person.h
plorg.o:plorg.h

.PHONY: depend #Now the file will be updated each time it is called.
depend: c++.cc
	g++ -I headers -M $(CPPFLAGS) $^ > $@
	more depend

.PHONY:clean
clean:
	rm -rf *.o c++