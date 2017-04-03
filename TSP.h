#ifndef TSP_H
#define TSP_H

#include "stdafx.h"
#include <vector>
#include "graph.h"

double TSP_brute_force(Graph &graph);
bool hamiltonianCycle(Graph &graph);
bool hamiltonianCycleHelper(Graph &graph, std::vector<int> path, int pos);
bool canAddVertex(int vertex, Graph &graph, std::vector<int> path, int pos);
std::vector<int> TSP_brute_force_path();

#endif // TSP
