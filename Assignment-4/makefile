# Makefile for compiling tree.cpp into an executable named tree
# Set the compiler flags and targets
CXX = g++
CXXFLAGS = -Wall -g -std=c++11
TARGETS = tree BST BodmasTree

all: $(TARGETS) # Build all targets When 'make' is run without arguments

tree: tree.o # Link the object file to create the executable
	$(CXX) $(CXXFLAGS) -o tree tree.o

BST: BST.o # Link the object file to create the executable
	$(CXX) $(CXXFLAGS) -o BST BST.o

BodmasTree: BodmasTree.o # Link the object file to create the executable
	$(CXX) $(CXXFLAGS) -o BodmasTree BodmasTree.o

tree.o: tree.cpp # Compile the source file into an object file
	$(CXX) $(CXXFLAGS) -c tree.cpp

BST.o: BST.cpp # Compile the source file into an object file
	$(CXX) $(CXXFLAGS) -c BST.cpp
	
BodmasTree.o: BodmasTree.cpp # Compile the source file into an object file
	$(CXX) $(CXXFLAGS) -c BodmasTree.cpp

clean: # Remove object files and executables
	rm -f *.o $(TARGETS)

.PHONY: all clean # Declare non-file targets