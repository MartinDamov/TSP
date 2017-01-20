// Test for graphs

#include "stdafx.h" // Required from Visual Studio
#include "graph.h"
#include <iostream>
#include <string>

/*
	Manual input for a graph via the console.
*/
Graph manual_input() {
	int size;
	std::cout << "Enter number of vertices: ";
	std::cin >> size;
	Graph graph(size);
	for (int i = 0; i < size; i++) {
		int v1;
		int v2;
		double weight;
		std::cout << "Enter edge (in the form of: v1, v2) and weight (-1 to exit): ";
		std::cin >> v1 >> v2 >> weight;
		if (v1 <= 0) {
			break;
		}
		graph.AddEdge(v1, v2, weight);
	}
	
	return graph;
}

int main()
{
	/*
		Construct graphs, add edges to them and display them in console
	*/
	Graph graph1(4);
	graph1.AddEdge(1, 2, 10);
	graph1.AddEdge(1, 3, 12);
	graph1.AddEdge(2, 4, 11);

	// Display graph1
	graph1.display();

	// Empty line for seperation
	std::cout << std::endl;

	Graph graph2(5);
	graph2.AddEdge(1, 2, 10);
	graph2.AddEdge(2, 3, 11);
	graph2.AddEdge(3, 4, 12);
	graph2.AddEdge(4, 5, 13);
	graph2.AddEdge(3, 5, 14);
	graph2.AddEdge(2, 5, 15);

	// Display graph2
	graph2.display();
	
	// Checks for Graph member functions
	std::cout << graph2.HasEdge(1, 1) << std::endl;
	std::cout << graph2.HasEdge(1, 2) << std::endl;
	std::cout << graph2.GetEdgeWeight(1, 2) << std::endl;

	// Add pause so the console doesn't terminate
	std::cout << "Press ENTER to continue... ";
	std::cin.ignore();

    return 0;
}

