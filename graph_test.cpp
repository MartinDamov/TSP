// Test for graphs

#include "stdafx.h" // Required from Visual Studio
#include "graph.h"
#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <algorithm>

//TODO: Implement custom next_permutation
//TODO: Add speicification about DIMACS format + add the website ot github. Website is in dissertation bookmark
//TODO: Move manual_input and read_graph to graph.h and graph.cpp
//TODO: Create a data structore for an edge, instead of using a vector of strings
//TODO: Replace console output with exceptions
//TODO: Fix input of graph as it can accept only vertices below 9 (because of substr statements)
//TODO: Cannot construct a graph in read_graph. Error returned: variable corrupt
//TODO: Change to pointers

/*
	Manual input for a graph via the console.
*/
Graph manual_input() {
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

/*
	Read a graph file in DIMACS format.
	Get as parameter a file name (as well as the format of the file, for example: test.txt or graph.gr)
*/
// Change to Graph read+graph(std::string name) {
void read_graph(std::string name) {

	// Open file
	std::ifstream myfile(name);
	std::string line;

	int size = -1;
	std::vector<std::string> edges;

	if (myfile.is_open()) {
		// Read line by line
		while (getline(myfile, line)) {
			if (line.substr(0, 1) == "p") {
				// Get size
				size = stoi(line.substr(2, 1));
			}// end if
			else if (line.substr(0, 1) == "a") {
				// Get edges and add them to the vector
				edges.push_back(line.substr(2));
			}// end else if
		}// end while

		// Close file
		myfile.close();
	
	}// end outer if
	else {
		std::cout << "Error! File could not be opened!" << std::endl;
	}
	/*
	if (size != -1) {
		// Construct a graph
		Graph graph(size);

		// Add edges
		for (int i = 0; i < edges.size(); i++) {
			// Get vertices and weight between them
			std::string edge = edges[i];
			int v1 = stoi(edge.substr(0, 1));
			int v2 = stoi(edge.substr(2, 1));
			double weight = stoi(edge.substr(4));

			// Add the edge
			graph.AddEdge(v1, v2, weight);
		} // end for

		//return graph;
	} // end if
	else {
		std::cout << "Error! Size not defined in file!" << std::endl;
	}
	*/
} // end read graph

double TSP_brute_force(Graph graph) {
	
	// Get all edges of the graph
	std::vector<Edge> edges = graph.GetAllEdges();
	int last = edges.size()-1;

	// Create permutations
	while (std::next_permutation(edges[0], edges[last])) {
		// Check for min value
		
	}

	return 21.0;
}

int main()
{
	/*
		Construct graphs, add edges to them and display them in console
	*/
	Graph graph1(4);
	graph1.AddEdge(1, 2, 10);
	graph1.AddEdge(1, 3, 12);
	graph1.AddEdge(2, 4, 11);

	// Display graph1
	graph1.display();

	// Empty line for seperation
	std::cout << std::endl;

	Graph graph2(5);
	graph2.AddEdge(1, 2, 10);
	graph2.AddEdge(2, 3, 11);
	graph2.AddEdge(3, 4, 12);
	graph2.AddEdge(4, 5, 13);
	graph2.AddEdge(3, 5, 14);
	graph2.AddEdge(2, 5, 15);

	// Display graph2
	graph2.display();

	// Seperation line
	std::cout << std::endl;

	// Test for member function GetAllEdges
	std::vector<Edge> edges = graph2.GetAllEdges();
	for (int i = 0; i < edges.size(); i++) {
		std::cout << edges[i].getVertex1() << " " 
			<< edges[i].getVertex2() << std::endl;
	}

	// Seperation line
	std::cout << std::endl;
	
	double test = TSP_brute_force(graph1);

	// Seperation line
	std::cout << std::endl;

	// Checks for Graph member functions
	std::cout << graph2.HasEdge(1, 1) << std::endl;
	std::cout << graph2.HasEdge(1, 2) << std::endl;
	std::cout << graph2.GetEdgeWeight(1, 2) << std::endl;

	//read_graph("test.txt");

	// Seperation line
	std::cout << std::endl;

	// Add pause so the console doesn't terminate
	std::cout << "Press ENTER to continue... ";
	std::cin.ignore();



    return 0;
}

