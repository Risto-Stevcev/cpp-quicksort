CC = clang++
CXX = clang++

CFLAGS = -g -Wall -O3 $(shell pkg-config --cflags cppunit)
LDFLAGS = -g -Wall $(shell pkg-config --libs cppunit)

.PHONY:
default: Main

.PHONY:
test: TestQuickSort

Main: Main.o QuickSort.o

TestQuickSort: TestQuickSort.o QuickSort.o

QuickSort.o: QuickSort.h

.PHONY:
all: clean default test

.PHONY:
clean:
	rm -f *.o *.h.gch *.*~ a.out Main TestQuickSort
