#ifndef EDGE_H
#define EDGE_H

#include "stdafx.h"
#include <iostream>

/**
	This is a representation of a graph edge
*/

class Edge {

public:

	Edge(const int v1, const int v2, const double weight);
	//Edge(Edge &other);
	~Edge();

	const int getVertex1();
	const int getVertex2();
	const double getWeight();

	const Edge &operator=(Edge &other);
	const friend bool operator<(const Edge &edge1, const Edge &edge2);
	const friend bool operator==(const Edge &edge1, const Edge &edge2);

private:
	int v1_;
	int v2_;
	double weight_;
};

#endif // EDGE
