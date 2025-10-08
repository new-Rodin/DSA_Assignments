// bfs_dfs_find_trees.cpp
#include "graph.h"
#include <iostream>
#include <vector>
#include <queue>
#include <stack>

// BFS: returns parent array (parent[x] = parent of x in BFS tree, -1 for root / unreachable)
std::vector<int> BFS_tree(const Graph &g, int src) {
    std::vector<int> parent(g.V, -1);
    std::vector<char> vis(g.V, 0);
    std::queue<int> q;

    vis[src] = 1;
    q.push(src);
    parent[src] = -1; // root has no parent

    while(!q.empty()){
        int u = q.front(); q.pop();
        for(int v: g.neighbors(u)){
            if(!vis[v]){
                vis[v] = 1;
                parent[v] = u;
                q.push(v);
            }
        }
    }
    return parent;
}

// Iterative DFS: returns parent array for DFS forest/tree starting at src
std::vector<int> DFS_tree(const Graph &g, int src) {
    std::vector<int> parent(g.V, -1);
    std::vector<char> vis(g.V, 0);
    std::stack<int> st;

    st.push(src);
    parent[src] = -1;

    while(!st.empty()){
        int u = st.top(); st.pop();
        if(vis[u]) continue;
        vis[u] = 1;
        for(int v: g.neighbors(u)){
            if(!vis[v]){
                parent[v] = u;
                st.push(v);
            }
        }
    }
    return parent;
}

int main(){
    std::cout << "BFS/DFS Tree demo\nEnter number of vertices: ";
    int n; if(!(std::cin >> n)) return 0;
    Graph g(n);
    std::cout << "Enter edges as pairs (u v). Enter -1 -1 to stop:\n";
    while(true){
        int u,v; std::cin >> u >> v;
        if(u == -1 && v == -1) break;
        g.addEdge(u, v); // assume addEdge checks bounds or user supplies valid 0..n-1
    }

    int src = 0;
    std::cout << "Enter source vertex for trees: ";
    std::cin >> src;

    auto pb = BFS_tree(g, src);
    auto pd = DFS_tree(g, src);

    std::cout << "BFS tree edges (parent -> node):\n";
    for(int i = 0; i < g.V; ++i) if(pb[i] != -1) std::cout << pb[i] << " -> " << i << "\n";

    std::cout << "DFS tree edges (parent -> node):\n";
    for(int i = 0; i < g.V; ++i) if(pd[i] != -1) std::cout << pd[i] << " -> " << i << "\n";

    return 0;
}
