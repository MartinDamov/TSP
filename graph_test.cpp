#include "stdafx.h"
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <chrono>
#include "graph.h"
#include "TSP.h"
#include "TSP_NN.h"


/**
	An example showing how the program works. All the output is displayed to the console
*/
void showExample() {
	
	// Construct graphs, add edges to them and display them in console
	Graph graph(4);
	graph.AddEdge(1, 2, 10);
	graph.AddEdge(1, 3, 10);
	graph.AddEdge(2, 3, 5);
	graph.AddEdge(1, 4, 20);
	graph.AddEdge(2, 4, 5);
	
	std::cout << "The following graph will be used to demonstrate the methods:" << std::endl;
	graph.display();

	// Seperation line
	std::cout << std::endl;

	// Detect time for brute force
	auto start_brute_force = std::chrono::high_resolution_clock::now();

	// Brute force
	std::cout << "Brute force distance: " << TSP_brute_force(graph) << std::endl;

	auto end_brute_force = std::chrono::high_resolution_clock::now();
	
	std::chrono::duration<double, std::milli> duration_brute_force = start_brute_force - end_brute_force;
	std::cout << "\n\nTime elapsed for TSP brute force: " << duration_brute_force.count();

	// Seperation lines
	std::cout << std::endl;
	std::cout << std::endl;

	// Detect time for branch and bound
	auto start_branch_bound = std::chrono::high_resolution_clock::now();

	// Nearest neighbour 
	std::cout << "NN distance: " << TSP_nearest_neighbour(graph) << std::endl;

	auto end_branch_bound = std::chrono::high_resolution_clock::now();

	std::chrono::duration<double, std::milli> duration_branch_bound = start_branch_bound - end_branch_bound;
	std::cout << "\n\nTime elapsed for TSP branch and bound: " << duration_branch_bound.count();

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
		//Graph graph = Graph();
		//Graph graph = Graph("dj38.tsp");
		//Graph graph = Graph("wi29.tsp");
		Graph graph = Graph("test.tsp");
		std::cout << "The inputed graph is: " << std::endl;
		graph.display();
		//std::cout << TSP_brute_force(graph) << std::endl;
		std::cout << TSP_nearest_neighbour(graph) << std::endl;

		// Seperation line
		std::cout << std::endl;

		int method;
		std::cout << "Choose a method - brute force (1) or branch and bound(2)" << std::endl;
		std::cin >> method;
		if (method < 2) {

			// Detect time for brute force
			auto start_brute_force = std::chrono::high_resolution_clock::now();

			// Call brute force

			auto end_brute_force = std::chrono::high_resolution_clock::now();

			std::chrono::duration<double, std::milli> duration_brute_force = start_brute_force - end_brute_force;
			std::cout << "\n\nTime elapsed for TSP brute force: " << duration_brute_force.count();

			char answer;
			std::cout << "\nWould you like to see the other method on the same graph? (y/n)" << std::endl;
			std::cin >> answer;
			if (answer == 'y') {
				// Detect time for branch and bound
				auto start_branch_bound = std::chrono::high_resolution_clock::now();

				// Call branch and bound

				auto end_branch_bound = std::chrono::high_resolution_clock::now();

				std::chrono::duration<double, std::milli> duration_branch_bound = start_branch_bound - end_branch_bound;
				std::cout << "\n\nTime elapsed for TSP branch and bound: " << duration_branch_bound.count();
			}

			// Add pause so the console doesn't terminate
			std::cin.ignore();
		}
		else {
			// Detect time for branch and bound
			auto start_branch_bound = std::chrono::high_resolution_clock::now();

			// Call branch and bound


			auto end_branch_bound = std::chrono::high_resolution_clock::now();

			std::chrono::duration<double, std::milli> duration_branch_bound = start_branch_bound - end_branch_bound;
			std::cout << "\n\nTime elapsed for TSP branch and bound: " << duration_branch_bound.count();

			char answer;
			std::cout << "\nWould you like to see the other method on the same graph? (y/n)" << std::endl;
			std::cin >> answer;
			if (answer == 'y') {
				// Detect time for brute force
				auto start_brute_force = std::chrono::high_resolution_clock::now();

				// Call brute force


				auto end_brute_force = std::chrono::high_resolution_clock::now();

				std::chrono::duration<double, std::milli> duration_brute_force = start_brute_force - end_brute_force;
				std::cout << "\n\nTime elapsed for TSP brute force: " << duration_brute_force.count();

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