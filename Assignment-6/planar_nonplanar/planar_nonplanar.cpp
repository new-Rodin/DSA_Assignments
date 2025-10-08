// planar_nonplanar.cpp
#include "graph.h"
#include <iostream>
#include <sstream>


// Simple CLI demonstration
// Accepts commands (menu): addv, adde u v, removee u v, display, checkplanar, exit


int main() {
std::cout << "Planar / Non-planar graph program\n";
int n; std::cout << "Enter initial number of vertices: ";
if(!(std::cin >> n)) return 0;
Graph g(n);


std::string cmd;
while (true) {
std::cout << "cmd> ";
if(!(std::cin >> cmd)) break;
if (cmd == "addv") {
g.addVertex();
std::cout << "Added vertex. New V=" << g.V << "\n";
} else if (cmd == "adde") {
int u,v; std::cin >> u >> v; g.addEdge(u,v);
} else if (cmd == "removee") {
int u,v; std::cin >> u >> v; g.removeEdge(u,v);
} else if (cmd == "display") {
g.display();
} else if (cmd == "checkplanar") {
bool planar = g.isPlanarKuratowski();
std::cout << (planar?"Likely Planar (no K5 or K3,3 found)":"Non-planar (K5 or K3,3 detected)") << "\n";
} else if (cmd == "exit") break;
else {
std::cout << "Commands: addv, adde u v, removee u v, display, checkplanar, exit\n";
std::string rest; std::getline(std::cin, rest);
}
}
return 0;
}