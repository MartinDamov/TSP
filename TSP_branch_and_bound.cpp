#include "stdafx.h"
#include <iostream>
#include <algorithm>
#include <vector>
#include <numeric>
#include <limits>
#include "TSP_branch_and_bound.h"

// Variables to be used for the solution
int size;
const int DEFAULT_SIZE = 5;
double adjacency_matrix[DEFAULT_SIZE][DEFAULT_SIZE];
std::vector<int> visited;
std::vector<int> path;
double distance = 0;

// Get the needed data from the graph
void TSP_branch_and_bound_set_graph(Graph &graph) {
	size = graph.size();
	visited.resize(size);

	// Resize and copy the adjacency matrix
	adjacency_matrix[size][size];
	for (int i = 0; i < size; i++) {
		for (int j = 0; j < size; j++) {
			adjacency_matrix[i][j] = graph.adjacency_matrix_[i][j];
		}
	}
}

void TSP_branch_and_bound_minimum_cost(int vertex) {
	int nearest_vertex;
	visited[vertex] = 1;
	// Add to the path
	path.push_back(vertex + 1);
	// Get nearest vertex
	nearest_vertex = TSP_branch_and_bound(vertex);
	if (nearest_vertex == std::numeric_limits<int>::max()) {
		nearest_vertex = 0;
		path.push_back(nearest_vertex + 1);
		distance += adjacency_matrix[vertex][nearest_vertex];
		return;
	}
	// Recursive call
	TSP_branch_and_bound_minimum_cost(nearest_vertex);
}


int TSP_branch_and_bound(int vertex) {

	// Initialize variables
	double temp = 0;
	double minimum = std::numeric_limits<double>::max();
	int nearest_vertex = std::numeric_limits<int>::max();

	for (int count = 0; count < size; count++) {
		if ((adjacency_matrix[vertex][count] != 0) && (visited[count] == 0)) {

			// Check for better solution
			if (adjacency_matrix[vertex][count] < minimum) {
				minimum = adjacency_matrix[count][0] +
					adjacency_matrix[vertex][count];
			}
			// Set nearest vertex
			temp = adjacency_matrix[vertex][count];
			nearest_vertex = count;
		}
	}
	if (minimum != std::numeric_limits<int>::max()) {
		distance += temp;
	}

	return nearest_vertex;
}

double TSP_branch_and_bound_distance() {
	TSP_branch_and_bound_minimum_cost(0);
	return distance;
}

std::vector<int> TSP_branch_and_bound_path() {
	return path;
}