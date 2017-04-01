#ifndef TSP_BRANCH_AND_BOUND_H
#define TSP_BRANCH_AND_BOUND_H

#include "stdafx.h"
#include "graph.h"

void TSP_branch_and_bound_set_graph(Graph &graph);
int TSP_branch_and_bound(int vertex);
void TSP_branch_and_bound_minimum_cost(int vertex);
double TSP_branch_and_bound_distance();

#endif // TSP_BRANCH_AND_BOUND_H
