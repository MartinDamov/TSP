#include "stdafx.h"
#include <iostream>
#include "edge.h"


Edge::Edge(const int v1, const int v2, const double weight):
	v1_(v1), v2_(v2), weight_(weight) {}

/*
Edge::Edge(Edge &other) {
	v1_ = other.v1_;
	v2_ = other.v2_;
	weight_ = other.weight_;
	Edge(v1_, v2_, weight_);
}
*/

const Edge &Edge::operator=(Edge & other) {
	v1_ = other.v1_;
	v2_ = other.v2_;
	weight_ = other.weight_;
	return Edge(v1_, v2_, weight_);
}

Edge::~Edge() {
}

const int Edge::getVertex1() { return v1_; }

const int Edge::getVertex2() { return v2_; }

const double Edge::getWeight() { return weight_; }

const bool operator<(const Edge & edge1, const Edge & edge2) {
	if (edge1.v1_ < edge2.v1_ && edge1.v2_ < edge2.v2_) {
		return true;
	}
	return false;
}

const bool operator==(const Edge &edge1, const Edge &edge2) {
	if (edge1.v1_ == edge2.v2_ && edge1.v1_ == edge2.v2_) {
		return true;
	}
	return false;
}