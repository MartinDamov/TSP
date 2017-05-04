#include "stdafx.h"
#include <gtest\gtest.h>
#include "graph.h"

TEST(GraphTest, NoEdges) {
	int size = 4;
	Graph graph(size);
	for (int i = 0; i < size; i++) {
		for (int j = 0; j < size; j++) {
			EXPECT_FALSE(graph.HasEdge(i, j));
		}
	}
}

TEST(GraphTest, HasEdges) {
	int size = 4;
	Graph graph(size);
	graph.AddEdge(1, 2, 10);
	graph.AddEdge(1, 3, 15);
	graph.AddEdge(1, 4, 20);
	graph.AddEdge(2, 3, 6);
	graph.AddEdge(3, 4, 4);
	for (int i = 0; i < size; i++) {
		for (int j = 0; j < size; j++) {
			EXPECT_TRUE(graph.HasEdge(i, j));
		}
	}
}

TEST(GraphTest, AddEdges) {
	int size = 3;
	Graph graph(size);
	for (int i = 0; i < size; i++) {
		for (int j = 0; j < size; j++) {
			EXPECT_FALSE(graph.HasEdge(i, j));
		}
	}
	graph.AddEdge(1, 2, 10);
	graph.AddEdge(2, 3, 5);
	graph.AddEdge(1, 3, 15);
	for (int i = 0; i < size; ++i) {
		for (int j = 0; j < size; ++j) {
			EXPECT_TRUE(graph.HasEdge(i, j));
		}
	}
}
/*

TEST(GraphTest, GetDegSeqStringTest) {
  {
    vector<string> v({"010", "101", "010"});
    Graph g(v);
    EXPECT_EQ("112", g.GetDegSeqString());
  }
  {
    vector<string> v({"0111", "1011", "1101", "1110"});
    Graph g(v);
    EXPECT_EQ("3333", g.GetDegSeqString());
  }
  {
    vector<string> v({"0101", "1010", "0100", "1000"});
    Graph g(v);
    EXPECT_EQ("1122", g.GetDegSeqString());
  }
  {
    vector<string> v({"0110", "1001", "1000", "0100"});
    Graph g(v);
    EXPECT_EQ("1122", g.GetDegSeqString());
  }
}
*/