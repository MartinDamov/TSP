
#ifndef GRAPH_H
#define GRAPH_H

#include "stdafx.h" // Required from Visual Studio

/** 
	This is a representation of an
	undricted weighted graph using an adgacency matrix.
	No self-loops are allowed.
*/

class Graph {

public:

	Graph(const int size);
	Graph(Graph &other);
	~Graph();

	int size() const;
	void AddEdge(const int v1, const int v2, const double weight);
	double GetEdgeWeight(const int v1, const int v2);
	bool HasEdge(const int v1, const int v2) const;
	void RemoveEdge(const int v1, const int v2);
	void display() const;

	Graph &operator=(Graph &other);

private:
	// Default size for an matrix
	static const int DEFAULT_SIZE = 5;
	int size_;
	// An two-dimensional array for holding an undricted weighted graph
	double adjacency_matrix_[DEFAULT_SIZE][DEFAULT_SIZE];
};


#endif // GRAPH

