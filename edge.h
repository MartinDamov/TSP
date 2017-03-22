#ifndef EDGE_H
#define EDGE_H

/**
This is a representation of an edge
*/

class Edge {

public:

	Edge(const int v1, const int v2, const double weight);
	~Edge();

	const int getVertex1();
	const int getVertex2();
	const double getWeight();

	friend bool operator==(const Edge &edge1, const Edge &edge2);

private:
	const int v1_;
	const int v2_;
	const double weight_;
};

#endif // EDGE
