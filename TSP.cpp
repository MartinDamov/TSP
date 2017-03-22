#include "stdafx.h"
#include <iostream>
#include <algorithm>
#include "graph.h"
#include "edge.h"
#include "TSP.h"

//TODO: Test permute function

double TSP_brute_force(Graph & graph) {
	
	// Get all edges of the graph
	std::vector<Edge> edges = graph.GetAllEdges();
	int last = edges.size() - 1;

	// Create permutations and check for min value
	std::vector<double> min_weight;
	double total_weight = 0;
	do {
		for (Edge edge : edges) {
			total_weight += edge.getWeight();
		}
		min_weight.push_back(total_weight);
	} while (std::next_permutation(edges.begin(), edges.end()));

	// Sort the vector the return the first (min) path
	std::sort(min_weight.begin(), min_weight.end());
	return min_weight[0];
}
