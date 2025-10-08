// graph.h
#ifndef GRAPH_H
#define GRAPH_H


#include <vector>
#include <algorithm>
#include <iostream>
#include <queue>
#include <stack>


class Graph {
public:
int V; // number of vertices
std::vector<std::vector<int>>* adj; // dynamically allocated adjacency list


Graph(int n = 0);
~Graph();


void addVertex();
void resize(int newV);
void addEdge(int u, int v, bool undirected = true);
void removeEdge(int u, int v, bool undirected = true);
void clearVertex(int u);
int degree(int u) const;
const std::vector<int>& neighbors(int u) const;
void display() const;


// Utilities used by program 1 (planarity tests)
bool hasK5() const;
bool hasK33() const;
bool isPlanarKuratowski() const; // returns true if NO K5 and NO K3,3 found
};


#endif // GRAPH_H