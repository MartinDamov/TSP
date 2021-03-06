#ifndef GRAPH_H
#define GRAPH_H

#include "stdafx.h"
#include <iostream>
#include <vector>
#include "edge.h"

/** 
	This is a representation of an
	undricted weighted graph using an adgacency matrix.
	No self-loops are allowed.
*/

class Graph {

public:

	Graph(); // manual input
	Graph(const int size);
	Graph(Graph &other);
	Graph(std::string name); // read from a file
	~Graph();

	const int size() const;
	void AddEdge(const int v1, const int v2, const double weight);
	const double GetEdgeWeight(const int v1, const int v2);
	bool HasEdge(const int v1, const int v2) const;
	void RemoveEdge(const int v1, const int v2);
	void display() const;
	std::vector<Edge> GetAllEdges() const;

	Graph &operator=(Graph &other);

	static const int DEFAULT_SIZE = 5;
	int size_;
	double adjacency_matrix_[DEFAULT_SIZE][DEFAULT_SIZE];
};


#endif // GRAPH