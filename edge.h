
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

	int getVertex1();
	int getVertex2();
	double getWeight();

private:
	// Vertex 1
	int v1_;
	// Vertex 1
	int v2_;
	double weight_;
};

#endif // EDGE
