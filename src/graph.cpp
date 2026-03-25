#include <iostream>

#include "graph.hpp"

int main()
{
	std::cout << "Undirected Graph (V=4, E=4)\n";
	Graph g(4, false);
	g.add_edge(0, 1);
	g.add_edge(0, 2);
	g.add_edge(1, 3);
	g.add_edge(2, 3);

	Matrix adj = g.adjacency_matrix();
	Matrix inc = g.incidence_matrix();

	std::cout << "\nAdjacency Matrix:\n";
	adj.print_list();

	std::cout << "\nIncidence Matrix:\n";
	inc.print_list();

	std::cout << "\n\nDirected Graph (V=4, E=4)\n";
	Graph dg(4, true);
	dg.add_edge(0, 1);
	dg.add_edge(0, 2);
	dg.add_edge(1, 3);
	dg.add_edge(2, 3);

	Matrix adj_d = dg.adjacency_matrix();
	Matrix inc_d = dg.incidence_matrix();

	std::cout << "\nAdjacency Matrix (Directed):\n";
	adj_d.print_list();

	std::cout << "\nIncidence Matrix (Directed):\n";
	inc_d.print_list();

	dg.visualize();

    g.visualize();

	return 0;
}
