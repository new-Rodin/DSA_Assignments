CXX = g++
CXXFLAGS = -std=c++17 -O2

# Targets
all: stack queue

stack: stack.cpp
	$(CXX) $(CXXFLAGS) stack.cpp -o stack

queue: queue.cpp
	$(CXX) $(CXXFLAGS) queue.cpp -o queue

clean:
	rm -f stack queue
