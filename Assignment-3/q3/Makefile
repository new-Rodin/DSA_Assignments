CXX = g++
CXXFLAGS = -std=c++17 -O2 -Wall

# executables
TARGETS = queue_ex stack_ex

all: $(TARGETS)

queue_ex: queue_ex.cpp queue.h
	$(CXX) $(CXXFLAGS) queue_ex.cpp -o queue_ex

stack_ex: stack_ex.cpp stack.h
	$(CXX) $(CXXFLAGS) stack_ex.cpp -o stack_ex

# run targets
run-queue: queue_ex
	./queue_ex

run-stack: stack_ex
	./stack_ex

# clean build files
clean:
	rm -f $(TARGETS)
