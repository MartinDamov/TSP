#include "stdafx.h"
#include <iostream>
#include <algorithm>
#include <vector>
#include <numeric>
#include <limits>
#include "graph.h"
#include "TSP.h"

std::vector<int> path_brute_force;
double distance_brute_force = std::numeric_limits<double>::max();

double TSP_brute_force(Graph &graph) {

	// Try to construct a hamiltonian cycle
	if (hamiltonianCycle(graph)) {
		std::sort(path_brute_force.begin()+1, path_brute_force.end()-1);
		do {
			double distance = 0.0;
			for (int i = 0; i < path_brute_force.size(); i++) {
				std::cout << path_brute_force[i] << " ";
				if (i > 0) {
					distance += graph.GetEdgeWeight(path_brute_force[i - 1], path_brute_force[i]);
				}		
			}

			// Add distance from the start vertex to the second
			distance += graph.GetEdgeWeight(path_brute_force[0], path_brute_force[1]);

			// Set best path
			if (distance < distance_brute_force) {
				distance_brute_force = distance;
			}

			std::cout << "dis: " << distance << std::endl;
		} while (std::next_permutation(path_brute_force.begin() + 1, path_brute_force.end() - 1));
	}

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

	// Change the vertex number from 0 to 1
	// (0 is used for the purpose of solving the task)
	path_brute_force[0] = 1;

	// Add the start vertex at the end to finish the connection
	// (This step is omited when adding to the path)
	path_brute_force.push_back(path_brute_force[0]);

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

std::vector<int> TSP_brute_force_path() {
	return path_brute_force;
}