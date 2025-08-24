# Makefile for compiling the linked list implementations
CXX = g++ # Compiler to use
CXXFLAGS = -Wall -Wextra -g # Flags for the compiler -Wextra is added to catch more warnings
TARGETS = SingleLL DoubleLL CircularLL # Name of final executable files

all:$(TARGETS)

SingleLL: SingleLL.o
	$(CXX) $(CXXFLAGS) -o SingleLL SingleLL.o
DoubleLL: DoubleLL.o
	$(CXX) $(CXXFLAGS) -o DoubleLL DoubleLL.o
CircularLL: CircularLL.o
	$(CXX) $(CXXFLAGS) -o CircularLL CircularLL.o

SingleLL.o: SingleLL.cpp
	$(CXX) $(CXXFLAGS) -c SingleLL.cpp
DoubleLL.o: DoubleLL.cpp
	$(CXX) $(CXXFLAGS) -c DoubleLL.cpp
CircularLL.o: CircularLL.cpp
	$(CXX) $(CXXFLAGS) -c CircularLL.cpp
# For cleaning the executable files and object files
clean:
	rm -f *.o $(TARGETS)
# To tell make that 'all' and 'clean' are not actual files
.PHONY: all clean

# Explanation of the flags used:
# -c: This flag tells the compiler to compile the source files into object files (.o files) without linking them. It allows you to compile each source file separately.
# -o: This flag specifies the name of the output file. When used with the compiler, it indicates the name of the executable file to be created after linking the object files. For example, `-o SingleLL` means the output executable will be named `SingleLL`.
# The `-c` flag is used when compiling source files to object files, while the `-o` flag is used when linking object files to create the final executable.
# The `-Wall` flag enables all compiler's warning messages, and `-Wextra` enables additional warning messages that are not included with `-Wall`. The `-g` flag includes debugging information in the compiled code, which is useful for debugging with tools like gdb.