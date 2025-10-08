CXX = g++
CXXFLAGS = -std=c++17 -O2

# Executable names
STACK_USING_QUEUE = stack_using_queue
QUEUE_USING_STACK = queue_using_stack
PERFORMANCE = performance

# Default target: build everything
all: $(STACK_USING_QUEUE) $(QUEUE_USING_STACK) $(PERFORMANCE)

# Compile each program
$(STACK_USING_QUEUE): stack_using_queue.cpp queue.h
	$(CXX) $(CXXFLAGS) stack_using_queue.cpp -o $@

$(QUEUE_USING_STACK): queue_using_stack.cpp stack.h
	$(CXX) $(CXXFLAGS) queue_using_stack.cpp -o $@

$(PERFORMANCE): performance.cpp stack.h queue.h
	$(CXX) $(CXXFLAGS) performance.cpp -o $@

# Run targets individually (with underscores)
run-stack_using_queue: $(STACK_USING_QUEUE)
	./$(STACK_USING_QUEUE)

run-queue_using_stack: $(QUEUE_USING_STACK)
	./$(QUEUE_USING_STACK)

run-performance: $(PERFORMANCE)
	./$(PERFORMANCE)

# Run everything in sequence
run: run-stack_using_queue run-queue_using_stack run-performance

# Clean target
clean:
	$(RM) $(STACK_USING_QUEUE) $(QUEUE_USING_STACK) $(PERFORMANCE)

.PHONY: all clean run run-stack_using_queue run-queue_using_stack run-performance
