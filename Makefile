CXX := g++
CXXFLAGS := -g -Wall --std=c++11
VALGRIND := valgrind --tool=memcheck --leak-check=yes

all: llrec-test

llrec-test: llrec.cpp llrec-test.cpp llrec.h
	$(CXX) $(CXXFLAGS) llrec.cpp llrec-test.cpp -o llrec-test

clean:
	rm -f *.o llrec-test *~

.PHONY: clean
