CXX = g++
CXXFLAGS = -std=c++17 -O2
SRC = performance.cpp
HEADERS = stack.h queue.h
TARGET = performance

.PHONY: all clean run run-performance

all: $(TARGET)

$(TARGET): $(SRC) $(HEADERS)
	$(CXX) $(CXXFLAGS) $(SRC) -o $(TARGET)

run: $(TARGET)
	./$(TARGET)

run-performance: $(TARGET)
	./$(TARGET)

clean:
	rm -f $(TARGET)
