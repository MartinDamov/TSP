#include "stdafx.h"
#include <iostream>
#include <algorithm>
#include <vector>
#include <numeric>
#include <limits>
#include "graph.h"
#include "TSP.h"

std::vector<int> path_brute_force(1);

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

			// Stop if the distance is worse the best saved one
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

std::vector<int> TSP_brute_force_path() {
	return path_brute_force;
}