#include "stdafx.h"
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include "graph.h"
#include "TSP.h"
#include "TSP_branch_and_bound.h"

/**
	An example showing how the program works. All the output is displayed to the console
*/
void showExample() {
	
	// Construct graphs, add edges to them and display them in console
	Graph graph(3);
	graph.AddEdge(1, 2, 10);
	graph.AddEdge(2, 3, 15);
	
	std::cout << "The following graph will be used to demonstrate the methods:" << std::endl;
	graph.display();

	// Seperation line
	std::cout << std::endl;

	// Brute force
	double distance_example = TSP_brute_force(graph);
	std::cout << "TSP brute force distance: " << distance_example << std::endl;
	std::vector<int> path_example = TSP_brute_force_path();
	std::cout << "TSP brute force path: ";
	for (int i = 0; i < path_example.size(); i++) {
		std::cout << path_example[i] << " ";
	}

	// Seperation lines
	std::cout << std::endl;
	std::cout << std::endl;

	// Branch and bound 
	TSP_branch_and_bound_set_graph(graph);
	double distance = TSP_branch_and_bound_distance();
	std::cout << "TSP branch and bound: " << distance << std::endl;
	std::cout << "TSP branch and bound path: ";
	std::vector<int> path = TSP_branch_and_bound_path();
	for (auto i = 0; i < path.size(); i++) {
		std::cout << path[i] << " ";
	}

	// Seperation line
	std::cout << std::endl;
	std::cout << std::endl;

	// Add pause so the console doesn't terminate
	std::cout << "Press ENTER to continue... ";
	std::cin.ignore();
}

int main() {
	
	char answer;
	std::cout << "Do you want to see an example? (y/n)" << std::endl;
	std::cin >> answer;
	if (answer == 'y') {
		showExample();
	}
	else {
		std::cout << "The next steps are for inputing a graph." << std::endl;
		
		// Input a graph by the console
		Graph graph = Graph();

		std::cout << "The inputed graph is: " << std::endl;
		graph.display();

		// Seperation line
		std::cout << std::endl;

		int method;
		std::cout << "Choose a method - brute force (1) or branch and bound(2)" << std::endl;
		std::cin >> method;
		if (method < 2) {
			// Call brute force
			double distance_brute_force = TSP_brute_force(graph);
			std::cout << "TSP brute force distance: " << distance_brute_force << std::endl;
			std::vector<int> path_brute_force = TSP_brute_force_path();
			std::cout << "TSP brute force path: ";
			for (int i = 0; i < path_brute_force.size(); i++) {
				std::cout << path_brute_force[i] << " ";
			}

			char answer;
			std::cout << "\nWould you like to see the other method on the same graph? (y/n)" << std::endl;
			std::cin >> answer;
			if (answer == 'y') {
				// Call branch and bound
				TSP_branch_and_bound_set_graph(graph);
				double distance_branch_and_bound = TSP_branch_and_bound_distance();
				std::cout << "TSP branch and bound: " << distance_branch_and_bound << std::endl;
				std::cout << "TSP branch and bound path: ";
				std::vector<int> path_branch_and_bound = TSP_branch_and_bound_path();
				for (auto i = 0; i < path_branch_and_bound.size(); i++) {
					std::cout << path_branch_and_bound[i] << " ";
				}
			}

			// Add pause so the console doesn't terminate
			std::cin.ignore();
		}
		else {
			// Call branch and bound
			TSP_branch_and_bound_set_graph(graph);
			double distance_branch_and_bound = TSP_branch_and_bound_distance();
			std::cout << "TSP branch and bound: " << distance_branch_and_bound << std::endl;
			std::cout << "TSP branch and bound path: ";
			std::vector<int> path_branch_and_bound = TSP_branch_and_bound_path();
			for (auto i = 0; i < path_branch_and_bound.size(); i++) {
				std::cout << path_branch_and_bound[i] << " ";
			}

			char answer;
			std::cout << "\nWould you like to see the other method on the same graph? (y/n)" << std::endl;
			std::cin >> answer;
			if (answer == 'y') {
				// Call brute force
				double distance_brute_force = TSP_brute_force(graph);
				std::cout << "TSP brute force distance: " << distance_brute_force << std::endl;
				std::vector<int> path_brute_force = TSP_brute_force_path();
				std::cout << "TSP brute force path: ";
				for (int i = 0; i < path_brute_force.size(); i++) {
					std::cout << path_brute_force[i] << " ";
				}
			}

			// Add pause so the console doesn't terminate
			std::cin.ignore();
		}
	}

	// Add pause so the console doesn't terminate
	std::cout << std::endl;
	std::cout << "Press ENTER to continue... ";
	std::cin.ignore();

    return 0;
}

