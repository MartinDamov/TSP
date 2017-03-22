#include "stdafx.h"
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include "graph.h"
#include "TSP.h"

int main() {

	// Construct graphs, add edges to them and display them in console
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

	// Seperation line
	std::cout << std::endl;

	// Test for member function GetAllEdges
	std::vector<Edge> edges = graph2.GetAllEdges();
	for (unsigned i = 0; i < edges.size(); i++) {
		std::cout << edges[i].getVertex1() << " " 
			<< edges[i].getVertex2() << std::endl;
	}

	// Seperation line
	std::cout << std::endl;
	
	double test = TSP_brute_force(graph1);

	std::cout << "TSP: " << test << std::endl;

	// Seperation line
	std::cout << std::endl;

	// Checks for Graph member functions
	std::cout << graph2.HasEdge(1, 1) << std::endl;
	std::cout << graph2.HasEdge(1, 2) << std::endl;
	std::cout << graph2.GetEdgeWeight(1, 2) << std::endl;

	//read_graph("test.txt");

	// Seperation line
	std::cout << std::endl;

	// Add pause so the console doesn't terminate
	std::cout << "Press ENTER to continue... ";
	std::cin.ignore();

    return 0;
}

