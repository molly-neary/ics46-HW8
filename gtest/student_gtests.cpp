#include <gtest/gtest.h>

#include "graph.h"

//to make fake graph from small.txt
Graph small_txt() {
    Graph G;
    G.numVertices = 4;
    G.push_back(Edge{0, 3, 1});
    G.push_back(Edge{3, 0, 3});
    G.push_back(Edge{1, 0, 5});
    G.push_back(Edge{3, 1, 2});
    G.push_back(Edge{2, 3, 8});
    G.push_back(Edge{1, 2, 3});
    return G;
}

TEST(TestGraph, DisjointSetFunctions) {
 	DisjointSet ds(4);
    EXPECT_EQ(ds.findSet(0), 0);
    EXPECT_EQ(ds.findSet(1), 1);
    ds.unionSets(0, 1);
    EXPECT_EQ(ds.findSet(0), ds.findSet(1));
 }

TEST(TestGraph, Sort) {
	Graph G = small_txt();
    Graph sortedG = G.sort_edges();
    ASSERT_EQ(sortedG.size(), 6);
    EXPECT_EQ(sortedG[0].weight, 1);
    EXPECT_EQ(sortedG[5].weight, 8);
}

TEST(TestGraph, EdgesFrom) {
	Graph G = small_txt();
    VertexList adjacent = G.edges_from(0);
    EXPECT_EQ(adjacent[0], 3);
}

TEST(TestGraph, Kruskal) {
	Graph G = small_txt();
    EdgeList mst = Kruskals(G);
    int sum_weight = sum_weights(mst);
    EXPECT_EQ(sum_weight, 6);
    EXPECT_EQ(mst.size(), 3);
}

TEST(TestGraph, DSF) {
	Graph G = small_txt();
    VertexList dfsearch = dfs(G, 0);
    VertexList expected = {0, 3, 1, 2};
    EXPECT_EQ(dfsearch, expected);
}

TEST(TestGraph, BSF) {
	Graph G = small_txt();
    VertexList bfsearch = bfs(G, 0);
    VertexList expected = {0, 3, 1, 2};
    EXPECT_EQ(bfsearch, expected);
}


