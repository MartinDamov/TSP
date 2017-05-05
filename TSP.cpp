#include "stdafx.h"
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include "graph.h"

double TSP_brute_force(Graph &graph) {

	double best_distance = std::numeric_limits<double>::max();
	std::vector<int> best_tour;
	std::vector<int> tour(graph.size());

	// Create default tour
	for (int i = 0; i < tour.size(); i++) {
		tour[i] = i;
	}

	// Try all permutations
	while (std::next_permutation(tour.begin() + 1, tour.end())) {
		
		// Calculate distance
		double current_distance = graph.GetEdgeWeight(tour[0], tour[tour.size()-1]);
		for (int i = 1; i < tour.size(); i++) {
			current_distance += graph.GetEdgeWeight(tour[i - 1], tour[i]);
		}

		if (current_distance < best_distance) {
			// A better tour has been found
			best_distance = current_distance;
			best_tour = tour;
		}

	}

	// Print the tour
	std::cout << "Tour: ";
	for (int i = 0; i < best_tour.size(); i++) {
		std::cout << best_tour[i] << " ";
	}

	return best_distance;
}