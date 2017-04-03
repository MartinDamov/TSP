#include "stdafx.h"
#include <iostream>
#include <algorithm>
#include <vector>
#include <numeric>
#include <limits>
#include "graph.h"
#include "TSP.h"

std::vector<int> path_brute_force;
double distance_brute_force = 0.0;

double TSP_brute_force(Graph &graph) {

	// Try to construct a hamiltonian cycle
	hamiltonianCycle(graph);
	return distance_brute_force;
}

// Hamiltonian cycle with backtracking
bool hamiltonianCycle(Graph &graph) {

	// Define vector size and fill it with -1's
	path_brute_force.resize(graph.size());
	path_brute_force.assign(graph.size(), -1);

	// Define starting point
	path_brute_force[0] = 0;

	// Solution can't be calculated because hamiltonian cycle doesn't exist
	if (hamiltonianCycleHelper(graph, path_brute_force, 1) == false) {
		std::cout << "Exact solution can't be found! There isn't Hamiltonian cycle!" << std::endl;
		return false;
	}

	return true;
}

// Hamiltonian cycle solver
bool hamiltonianCycleHelper(Graph &graph, std::vector<int> path, int pos) {
	if (pos == graph.size()) {
		if (graph.HasEdge(path[pos - 1], path[0])) {
			return true;
		}

		return false;
	}

	for (int vertex = 1; vertex < graph.size(); vertex++) {
		
		// Check if we can add the vertex
		if (canAddVertex(vertex, graph, path, pos)) {
			path[pos] = vertex;
			path_brute_force[pos] = vertex + 1;

			// Recursive call
			if (hamiltonianCycleHelper(graph, path, pos + 1) == true) {
				return true;
			}
			path[pos] = -1;
			path_brute_force[pos] = -1;
		}
	}

	return false;
}

// Check if vertex can be added in the Hamiltonian cycle at the position index
bool canAddVertex(int vertex, Graph &graph, std::vector<int> path, int pos) {
	
	// There is no vertex there
	// For detection of invalid vertex is used 0
	// (as in the graph implementaion, a 0 represent there is no edge)
	if (graph.adjacency_matrix_[path[pos - 1]][vertex] == 0) {	
		return false; 
	}

	for (int i = 0; i < pos; i++) {
		if (path[i] == vertex) {
			return false;
		}
	}

	return true;
}

/*
double TSP_brute_force(Graph &graph) {
	int size = graph.size();
	std::vector<int> route(size);

	// Fill the range with sequentially increasing values
	std::iota(route.begin(), route.end(), 0);

	double best_distance = std::numeric_limits<double>::max();

	// Use std::next_permutation to check all possible cases and find best route
	do {
		path_brute_force.clear();
		double distance = 0.0;
		for (auto i = 1; i < route.size(); i++) {

			// Calculate distance
			distance += graph.adjacency_matrix_[route[i - 1]][route[i]];
			path_brute_force.push_back(route[i]);

			// Stop if the distance is worse than best saved one
			if (distance > best_distance) {
				path_brute_force.clear();
				break;
			}
		}

		// Check if better solutions was found (lower distance)
		distance += graph.adjacency_matrix_[route[size - 1]][0];
		if (distance < best_distance) {
			best_distance = distance;
		}

	} while (std::next_permutation(route.begin() + 1, route.end()));

	return best_distance;
}
*/
std::vector<int> TSP_brute_force_path() {
	// Change the vertex number from 0 to 1
	// (0 is used for the purpose of solving the task)
	path_brute_force[0] = 1;
	
	// Add the start vertex at the end to finish the connection
	// (This step is omited when adding to the path)
	path_brute_force.push_back(path_brute_force[0]);
	return path_brute_force;
}