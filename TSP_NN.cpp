#include "stdafx.h"
#include <vector>
#include <algorithm>
#include "graph.h"
#include "TSP_NN.h"


double TSP_nearest_neighbour(Graph &graph) {
	double distance = 0.0;
	std::vector<int> visited;
	std::vector<int> tour;
	int start_vertex = 0;
	int next_vertex;
	int current_vertex = start_vertex; // This is the start vertex
	double min = std::numeric_limits<double>::max();
	tour.push_back(current_vertex);

	int number_of_vertices = graph.size();

	for (int i = 0; i < number_of_vertices; i++) {

		// The vertex has been visited
		visited.push_back(current_vertex);
		double min = std::numeric_limits<double>::max();
		next_vertex = 0;

		// Find nearest vertex
		for (int j = 0; j < number_of_vertices; j++) {
			if (j != current_vertex && std::find(visited.begin(), visited.end(), j) == visited.end()) {
				// Vertex has not been visited and it is not the current one
				if (min > graph.GetEdgeWeight(current_vertex, j)) {
					min = graph.GetEdgeWeight(current_vertex, j);
					next_vertex = j;
				}
			}
		}

		// Add the vertex to the tour
		tour.push_back(next_vertex);
		// Calculate the distance
		distance += graph.GetEdgeWeight(current_vertex, next_vertex);
		// Set the current vertex
		current_vertex = next_vertex;
	}

	std::cout << "\nTour: ";
	for (int i = 0; i < tour.size(); i++) {
		std::cout << tour[i] << " ";
	}
	std::cout << std::endl;

	return distance;
}
