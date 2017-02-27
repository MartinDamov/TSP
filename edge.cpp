#include "stdafx.h"
#include "edge.h"
#include <iostream>


Edge::Edge(int v1, int v2, double weight)
{
	v1_ = v1;
	v2_ = v2;
	weight_ = weight;
}

Edge::~Edge()
{
}

const int Edge::getVertex1() { return v1_; }

const int Edge::getVertex2() { return v2_; }

const double Edge::getWeight() { return weight_; }

bool operator==(const Edge &edge1, const Edge &edge2) {
	if (edge1.v1_ == edge2.v2_ && edge1.v1_ == edge2.v2_) {
		return true;
	}
	return false;
}