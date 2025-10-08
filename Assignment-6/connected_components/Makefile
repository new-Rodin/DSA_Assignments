CXX = g++
CXXFLAGS = -std=c++17 -O2 -Wall -pipe

all: connected_components

connected_components: connected_components.cpp graph.cpp graph.h
	$(CXX) $(CXXFLAGS) -o connected_components connected_components.cpp graph.cpp

clean:
	rm -f connected_components

.PHONY: all clean
