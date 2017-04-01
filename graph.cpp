#include "stdafx.h"
#include <fstream>
#include <string>
#include <vector>
#include <iostream>
#include "graph.h"
#include "edge.h"


Graph::Graph(const int size) {
	size_ = size;
	adjacency_matrix_[size][size];
	
	// Fill the adjacency matrix with zeros
	for (int i = 0; i < size; i++) {
		for (int j = 0; j < size; j++) {
			adjacency_matrix_[i][j] = 0;
		}
	}
}

Graph::Graph(Graph &other) {
	size_ = other.size();
	Graph graph(size_);
	int v1 = 0;
	int v2 = 0;
	for (int i = 0; i <= size_; i++) {
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

const int Graph::size() const { return size_; }

void Graph::AddEdge(const int v1, const int v2, const double weight) {
	// Check if edge is valid (if vertices and edge weight are correct)
	if (v1 > size_ || v2 > size_ || v1 <= 0 || v2 <= 0 || v1 == v2 || weight <= 0 || HasEdge(v1, v2)) {
		std::cout << "Invalid edge!" << std::endl;
	}
	// If the edge is valid add the edge weight
	else {
		adjacency_matrix_[v1 - 1][v2 - 1] = weight;
		adjacency_matrix_[v2 - 1][v1 - 1] = weight;
	}
}

// Return the weight of the edge
const double Graph::GetEdgeWeight(const int v1, const int v2) {
	return adjacency_matrix_[v1 - 1][v2 - 1];
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
		}
		std::cout << std::endl;
	}// outer for
}

// Return a vector containing all edges of the graph
std::vector<Edge> Graph::GetAllEdges() const
{
	std::vector<Edge> edges;

	for (int i = 1; i < size_ + 1; i++) {
		for (int j = 1; j < size_ + 1; j++) {
			if (HasEdge(i, j)) {
				Edge edge(i, j, adjacency_matrix_[i - 1][j - 1]);
				edges.push_back(edge);
			} // end if
		} // end inner for
	} // end outer for

	return edges;
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

// Manual input for a graph via the console.
Graph Graph::manual_input() {
	int size;
	std::cout << "Enter number of vertices: ";
	std::cin >> size;
	Graph graph(size);
	for (int i = 0; i < size; i++) {
		int v1;
		int v2;
		double weight;
		std::cout << "Enter edge (in the form of: v1, v2) and weight (-1 -1 -1 to exit): ";
		std::cin >> v1 >> v2 >> weight;
		if (v1 <= 0) {
			break;
		}
		graph.AddEdge(v1, v2, weight);
	}

	return graph;
}

/**
	Read a graph file in DIMACS format.
	Get as parameter a file name (as well as the format of the file, for example: test.txt or graph.gr)
*/
Graph Graph::read_graph(std::string name) {

	// Open file
	std::ifstream myfile(name);
	std::string line;

	int size = -1;
	std::vector<std::string> edges;

	if (myfile.is_open()) {
		while (getline(myfile, line)) {
			if (line.substr(0, 1) == "p") {
				// Get size
				size = stoi(line.substr(2, 1));
			}
			else if (line.substr(0, 1) == "a") {
				// Get edges and add them to the vector
				edges.push_back(line.substr(2));
			}
		}// end while

		myfile.close();
	}// end outer if
	else {
		std::cout << "Error! File could not be opened!" << std::endl;
		abort();
	}

	if (size != -1) {
		Graph graph(size);

		// Add edges
		for (unsigned i = 0; i < edges.size(); i++) {
			// Get vertices and weight between them
			std::string edge = edges[i];
			char delimiter(' ');
			std::string v1_ = edge.substr(0, edge.find(delimiter));
			std::string v2_ = edge.substr(v1_.length() - 1, edge.find(delimiter));
			std::string weight_ = edge.substr(v2_.length() - 1, edge.find(delimiter));;
			int v1 = stoi(v1_);
			int v2 = stoi(v2_);
			double weight = stoi(weight_);

			// Add the edge
			graph.AddEdge(v1, v2, weight);
		}

		return graph;
	} 
	else {
		std::cout << "Error! Size not defined in file!" << std::endl;
		abort();
	}

} // end read graph