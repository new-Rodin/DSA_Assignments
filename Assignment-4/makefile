# Makefile for compiling tree.cpp into an executable named tree
# Set the compiler flags and targets
CXX = g++
CXXFLAGS = -Wall -g -std=c++11
TARGETS = tree

all: $(TARGETS) # Build all targets When 'make' is run without arguments

tree: tree.o # Link the object file to create the executable
	$(CXX) $(CXXFLAGS) -o tree tree.o  

tree.o: tree.cpp # Compile the source file into an object file
	$(CXX) $(CXXFLAGS) -c tree.cpp

clean: # Remove object files and executables
	rm -f *.o $(TARGETS)

.PHONY: all clean # Declare non-file targets