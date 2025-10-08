CXX = g++
CXXFLAGS = -std=c++17 -O2 -Wall -pipe

all: bfs_dfs_find_trees

bfs_dfs_find_trees: bfs_dfs_find_trees.cpp graph.cpp graph.h
	$(CXX) $(CXXFLAGS) -o bfs_dfs_find_trees bfs_dfs_find_trees.cpp graph.cpp

clean:
	rm -f bfs_dfs_find_trees

.PHONY: all clean
