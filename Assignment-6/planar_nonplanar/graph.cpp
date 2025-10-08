// graph.cpp
#include "graph.h"
#include <algorithm>
#include <iostream>

// --- Constructor / Destructor ---
Graph::Graph(int n) : V(n) {
    adj = new std::vector<std::vector<int>>(n);
}

Graph::~Graph() {
    delete adj;
}

// --- Vertex / resizing ---
void Graph::addVertex() {
    adj->push_back(std::vector<int>());
    ++V;
}

void Graph::resize(int newV) {
    adj->resize(newV);
    V = newV;
}

// --- Edges ---
void Graph::addEdge(int u, int v, bool undirected) {
    if (u < 0 || v < 0) return;
    if (u >= V || v >= V) {
        int newV = std::max(u, v) + 1;
        resize(newV);
    }
    // avoid duplicate edges
    auto &au = (*adj)[u];
    if (std::find(au.begin(), au.end(), v) == au.end()) au.push_back(v);

    if (undirected) {
        auto &av = (*adj)[v];
        if (std::find(av.begin(), av.end(), u) == av.end()) av.push_back(u);
    }
}

void Graph::removeEdge(int u, int v, bool undirected) {
    if (u < 0 || v < 0 || u >= V || v >= V) return;
    auto &au = (*adj)[u];
    au.erase(std::remove(au.begin(), au.end(), v), au.end());
    if (undirected) {
        auto &av = (*adj)[v];
        av.erase(std::remove(av.begin(), av.end(), u), av.end());
    }
}

void Graph::clearVertex(int u) {
    if (u < 0 || u >= V) return;
    // remove u from neighbors
    for (int i = 0; i < V; ++i) {
        if (i == u) continue;
        auto &vec = (*adj)[i];
        vec.erase(std::remove(vec.begin(), vec.end(), u), vec.end());
    }
    // clear its adjacency list
    (*adj)[u].clear();
}

int Graph::degree(int u) const {
    if (u < 0 || u >= V) return 0;
    return static_cast<int>((*adj)[u].size());
}

const std::vector<int>& Graph::neighbors(int u) const {
    if (u < 0 || u >= V) {
        static const std::vector<int> empty;
        return empty;
    }
    return (*adj)[u];
}

void Graph::display() const {
    for (int i = 0; i < V; ++i) {
        std::cout << i << ": ";
        for (int v : (*adj)[i]) std::cout << v << " ";
        std::cout << "\n";
    }
}

// --- Helper: build adjacency matrix ---
static std::vector<std::vector<char>> buildMatrix(const Graph &g) {
    int n = g.V;
    std::vector<std::vector<char>> mat(n, std::vector<char>(n, 0));
    for (int i = 0; i < n; ++i) {
        for (int v : g.neighbors(i)) {
            if (v >= 0 && v < n) mat[i][v] = 1;
        }
    }
    return mat;
}

// --- K5 detection (naive combination) ---
bool Graph::hasK5() const {
    if (V < 5) return false;
    auto mat = buildMatrix(*this);
    std::vector<int> comb(5);
    // choose indices 0..V-1
    for (int a = 0; a < V-4; ++a) {
        for (int b = a+1; b < V-3; ++b) {
            for (int c = b+1; c < V-2; ++c) {
                for (int d = c+1; d < V-1; ++d) {
                    for (int e = d+1; e < V; ++e) {
                        int nodes[5] = {a,b,c,d,e};
                        bool complete = true;
                        for (int i = 0; i < 5 && complete; ++i) {
                            for (int j = i+1; j < 5; ++j) {
                                if (!mat[nodes[i]][nodes[j]] && !mat[nodes[j]][nodes[i]]) {
                                    complete = false; break;
                                }
                            }
                        }
                        if (complete) return true;
                    }
                }
            }
        }
    }
    return false;
}

// --- K3,3 detection (choose 3 and another disjoint 3) ---
bool Graph::hasK33() const {
    if (V < 6) return false;
    auto mat = buildMatrix(*this);
    // choose first triple A
    for (int a = 0; a < V-2; ++a) {
        for (int b = a+1; b < V-1; ++b) {
            for (int c = b+1; c < V; ++c) {
                // now choose triple B from remaining vertices
                for (int d = 0; d < V-2; ++d) {
                    if (d==a || d==b || d==c) continue;
                    for (int e = d+1; e < V-1; ++e) {
                        if (e==a || e==b || e==c) continue;
                        for (int f = e+1; f < V; ++f) {
                            if (f==a || f==b || f==c) continue;
                            // ensure disjoint: we already skipped equal indices
                            int A[3] = {a,b,c};
                            int B[3] = {d,e,f};
                            bool complete = true;
                            // check all cross edges exist (A_i to B_j)
                            for (int i = 0; i < 3 && complete; ++i) {
                                for (int j = 0; j < 3; ++j) {
                                    if (!mat[A[i]][B[j]] && !mat[B[j]][A[i]]) {
                                        complete = false; break;
                                    }
                                }
                            }
                            if (complete) return true;
                        }
                    }
                }
            }
        }
    }
    return false;
}

bool Graph::isPlanarKuratowski() const {
    // returns true when we did NOT find K5 or K3,3 (i.e., likely planar)
    return !(hasK5() || hasK33());
}
