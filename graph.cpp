
#include "stdafx.h" // Required from Visual Studio
#include "graph.h"
#include <iostream>

//TODO: Check member function
//TODO: Fix assignment operator
//TODO: Fix copy constructor

Graph::Graph(const int size) {
	size_ = size;
	// Create an array to hold the matrix
	adjacency_matrix_[size][size];
	
	// Fill the adjacency matrix with zeros
	for (int i = 0; i < size; i++) {
		for (int j = 0; j < size; j++) {
			adjacency_matrix_[i][j] = 0;
		}// inner for
	}// outer for
}

Graph::Graph(Graph &other) {
	size_ = other.size();
	Graph graph(size_);
	int v1 = 0;
	int v2 = 0;
	for (int i = 0; i < size_; i++) {
		if (other.HasEdge(v1, v2)) {
			double weight = other.GetEdgeWeight(v1, v2);
			graph.AddEdge(v1, v2, weight);
		}
		v1++;
		v2++;
	}
}

Graph::~Graph() {
	std::cout << "~Graph() was invoked" << std::endl;
}

int Graph::size() const { return size_; }

// Add an edge
void Graph::AddEdge(const int v1, const int v2, const double weight) {
	// Check if edge is valid (if vertices and edge weight are correct)
	if (v1 > size_ || v2 > size_ || v1 <= 0 || v2 <= 0 || v1 == v2 || weight <= 0 || HasEdge(v1, v2)) {
		std::cout << "Invalid edge!" << std::endl;
	}
	// If the edge is valid add the edge weight
	else {
		adjacency_matrix_[v1-1][v2-1] = weight;
	}
}

// Return the weight of the edge
double Graph::GetEdgeWeight(const int v1, const int v2) {
	return adjacency_matrix_[v1-1][v2-1];
}

// Return if vertices are connected
bool Graph::HasEdge(const int v1, const int v2) const {
	if (adjacency_matrix_[v1 - 1][v2 - 1] != 0) { return true; }
	return false;
}

void Graph::RemoveEdge(const int v1, const int v2) {
	adjacency_matrix_[v1 - 1][v2 - 1] = 0;
}

void Graph::display() const {
	for (int i = 0; i < size_; i++) {
		for (int j = 0; j < size_; j++) {
			std::cout << adjacency_matrix_[i][j] << " ";
		} // inner for
		std::cout << std::endl;
	}// outer for
}

Graph &Graph::operator=(Graph &other) {
	size_ = other.size();
	size_ = other.size();
	Graph graph(size_);
	int v1 = 0;
	int v2 = 0;
	for (int i = 0; i < size_; i++) {
		if (other.HasEdge(v1, v2)) {
			double weight = other.GetEdgeWeight(v1, v2);
			graph.AddEdge(v1, v2, weight);
		}
		v1++;
		v2++;
	}
	return graph;
}

