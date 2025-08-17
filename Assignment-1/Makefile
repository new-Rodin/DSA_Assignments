# Defining variables
CXX = g++ #Compiler to use
CXXFLAGS = -Wall -g #Flags
TARGETS = palindrome matrix #Name of final executable file

#The 'all' Rule 
all: $(TARGETS) #This is what happens when we just type make

#To link the object files into the final executable file
palindrome: palindr.o
		$(CXX) $(CXXFLAGS) -o palindrome palindr.o
matrix: matrix.o
		$(CXX) $(CXXFLAGS) -o matrix matrix.o

#To compile source files into object files
palindr.o: palindr.cpp
		$(CXX) $(CXXFLAGS) -c palindr.cpp
matrix.o: matrix.cpp
		$(CXX) $(CXXFLAGS) -c matrix.cpp
#For cleaning the executable file
clean:
	rm -f *.o $(TARGETS)

#To tell the make that 'all' and 'clean' are not actual files
.PHONY: all clean