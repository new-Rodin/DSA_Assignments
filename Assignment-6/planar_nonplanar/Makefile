CXX = g++
CXXFLAGS = -std=c++17 -O2 -Wall -pipe

all: planar_nonplanar

planar_nonplanar: planar_nonplanar.cpp graph.cpp graph.h
	$(CXX) $(CXXFLAGS) -o planar_nonplanar planar_nonplanar.cpp graph.cpp

clean:
	rm -f planar_nonplanar

.PHONY: all clean
