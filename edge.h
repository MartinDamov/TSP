#ifndef EDGE_H
#define EDGE_H

/**
This is a representation of an edge
*/

class Edge
{

public:

	Edge(int v1, int v2, double weight);
	~Edge();

	const int getVertex1();
	const int getVertex2();
	const double getWeight();

	friend bool operator==(const Edge &edge1, const Edge &edge2);

private:
	// Vertex 1
	int v1_;
	// Vertex 1
	int v2_;
	double weight_;
};

#endif // EDGE
