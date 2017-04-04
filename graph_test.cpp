#include "stdafx.h"
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include "graph.h"
#include "TSP.h"
#include "TSP_branch_and_bound.h"

int main() {

	// Construct graphs, add edges to them and display them in console
	Graph graph1(4);
	graph1.AddEdge(1, 2, 10);
	graph1.AddEdge(1, 3, 15);
	graph1.AddEdge(1, 4, 20);
	graph1.AddEdge(2, 3, 35);
	graph1.AddEdge(2, 4, 25);
	graph1.AddEdge(3, 4, 30);

	// Display graph1
	graph1.display();

	// Empty line for seperation
	std::cout << std::endl;

	Graph graph2(5);
	graph2.AddEdge(1, 2, 10);
	graph2.AddEdge(1, 3, 11);
	graph2.AddEdge(1, 4, 12);
	graph2.AddEdge(2, 3, 11);
	graph2.AddEdge(2, 4, 13);
	graph2.AddEdge(3, 4, 12);
	graph2.AddEdge(4, 5, 13);
	graph2.AddEdge(3, 5, 14);
	graph2.AddEdge(2, 5, 15);

	Graph ham(5);
	ham.AddEdge(1, 2, 2);
	ham.AddEdge(1, 4, 4);
	ham.AddEdge(2, 3, 3);
	ham.AddEdge(2, 4, 4);
	ham.AddEdge(2, 5, 5);
	ham.AddEdge(3, 5, 5);
	ham.AddEdge(4, 5, 5);

	ham.display();

	std::cout << std::endl;

	double dis = TSP_brute_force(ham);
	std::cout << "TSP brute force distance: " << dis << std::endl;
	std::vector<int> pathbrute = TSP_brute_force_path();
	std::cout << "TSP brute force path: ";
	for (int i = 0; i < pathbrute.size(); i++) {
		std::cout << pathbrute[i] << " ";
	}

	// Seperation line
	std::cout << std::endl;

	// Seperation line
	std::cout << std::endl;

	TSP_branch_and_bound_set_graph(ham);
	double distance = TSP_branch_and_bound_distance();
	std::cout << "TSP branch and bound: " << distance << std::endl;
	std::cout << "TSP branch and bound path: ";
	std::vector<int> path = TSP_branch_and_bound_path();
	for (auto i = 0; i < path.size(); i++) {
		std::cout << path[i] << " ";
	}

	// Seperation line
	std::cout << std::endl;

	// Seperation line
	std::cout << std::endl;

	// Add pause so the console doesn't terminate
	std::cout << "Press ENTER to continue... ";
	std::cin.ignore();

    return 0;
}

