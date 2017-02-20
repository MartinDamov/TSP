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

int Edge::getVertex1() { return v1_; }

int Edge::getVertex2() { return v2_; }

double Edge::getWeight() { return weight_; }
