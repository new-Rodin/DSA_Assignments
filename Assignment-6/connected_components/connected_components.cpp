// connected_components.cpp
#include "graph.h"
#include <iostream>
#include <vector>
#include <queue>


std::vector<std::vector<int>> components(const Graph &g) {
std::vector<char> vis(g.V, 0);
std::vector<std::vector<int>> comps;
for(int i=0;i<g.V;i++){
if(vis[i]) continue;
std::vector<int> comp;
std::queue<int> q; q.push(i); vis[i]=1;
while(!q.empty()){
int u = q.front(); q.pop();
comp.push_back(u);
for(int v: g.neighbors(u)){
if(!vis[v]){ vis[v]=1; q.push(v); }
}
}
comps.push_back(comp);
}
return comps;
}


int main(){
std::cout << "Connected components program\nEnter number of vertices: ";
int n; if(!(std::cin >> n)) return 0;
Graph g(n);
std::cout << "Enter edges as pairs (u v). Enter -1 -1 to stop:\n";
while(true){ int u,v; std::cin >> u >> v; if(u==-1 && v==-1) break; g.addEdge(u,v); }


auto comps = components(g);
std::cout << "Found " << comps.size() << " component(s)\n";
for(size_t i=0;i<comps.size();++i){
std::cout << "Component " << i << ": ";
for(int v: comps[i]) std::cout << v << " ";
std::cout << "\n";
}
return 0;
}