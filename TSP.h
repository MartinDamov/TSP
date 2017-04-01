#ifndef TSP_H
#define TSP_H

#include "stdafx.h"
#include <vector>
#include "graph.h"

double TSP_brute_force(Graph &graph);
std::vector<int> TSP_brute_force_path();

#endif // TSP
