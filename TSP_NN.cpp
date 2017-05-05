#include "stdafx.h"
#include <vector>
#include <algorithm>
#include <set>
#include "graph.h"
#include "TSP_NN.h"

double TSP_nearest_neighbour(Graph &graph) {
	double distance = 0;
	std::set<int> visited_vertices;
	std::vector<int> tour;
	int current_vertex = 3; // This is the start vertex
	bool start = true;
	visited_vertices.insert(current_vertex);
	tour.push_back(current_vertex);

	//while(visited_vertices.size() < graph.size()) {
	for (int j = 0; j < graph.size(); j++){
		int next_vertex = 0;
		double min = std::numeric_limits<double>::max();

		// Find nearest vertex
		for (int i = 0; i < graph.size(); i++) {

			if (i != current_vertex && graph.GetEdgeWeight(current_vertex, i) < min) {
				// Check if the vertex has been visited already (0 used for the start
				if (visited_vertices.find(i) != visited_vertices.end()) {
					next_vertex = i;
					visited_vertices.insert(next_vertex);
					distance += graph.GetEdgeWeight(current_vertex, next_vertex);
					current_vertex = next_vertex;
					min = graph.GetEdgeWeight(current_vertex, i);
					tour.push_back(next_vertex);
				}
			}
		}		
	}

	std::cout << "Tour: ";
	for (int i = 0; i < tour.size(); i++) {
		std::cout << tour[i] << " ";
	}
	std::cout << std::endl;

	return distance;
}