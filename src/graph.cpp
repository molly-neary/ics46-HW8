#include "graph.h"
#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>
#include <numeric>
#include <queue>
#include <stack>

void error(string msg){
	std::cout<<"Error: "<<msg<<std::endl;
}

//DisjointSet

DisjointSet::DisjointSet(int numVertices){
	subsets.resize(numVertices);
	for (int i = 0; i< numVertices; i++){subsets[i].parent = i;}
}

void DisjointSet::makeSet(Vertex x){
	if (x>= 0 && x< (int)subsets.size()) {subsets[x].parent = x;}
}

Vertex DisjointSet::findSet(Vertex x){
	if (subsets[x].parent != x) {
		subsets[x].parent = findSet(subsets[x].parent);
	}
	return subsets[x].parent;
}

void DisjointSet::unionSets(Vertex x, Vertex y){
	Vertex root_x = findSet(x);
	Vertex root_y = findSet(y);
	if (root_x==root_y) {
		error("x and y in same set");
		return;
	}
	subsets[root_y].parent = root_x;
}

//Graph

//helper for comparing (sorting)
bool compareWeights(const Edge& one, const Edge& two) {return one.weight < two.weight;}

// each vertex is an integer in range 0..numVertices-1
// returns a copy of graph with edges sorted ascending by edge weight
Graph Graph::sort_edges() const{
	Graph copy_graph  = *this;
	std::sort(copy_graph.begin(), copy_graph.end(), compareWeights);
	return copy_graph;
}

VertexList Graph::edges_from(Vertex vertex) const{
	VertexList adjacentEdges;
	for (const auto& edge: *this){
		if (edge.u == vertex){adjacentEdges.push_back(edge.v);}
	}
	return adjacentEdges;
}

//MST

EdgeList Kruskals(const Graph& G){
	EdgeList f;
	DisjointSet ds(G.numVertices);
	for (int i=0; i<G.numVertices; i++){ds.makeSet(i);}
	Graph sorted = G.sort_edges();
	for (const auto& edge: sorted) {
		if (ds.findSet(edge.u) != ds.findSet(edge.v)) {
		f.push_back(edge);
		ds.unionSets(edge.u, edge.v);
		}
	}
    return f;
}

// important for testing - the total cost of MST
int sum_weights(EdgeList const& L){
	int sum = 0;
	for (const auto& edge: L){sum += edge.weight;}
	return sum;
}

void file_to_graph(string filename, Graph & G){
	ifstream in(filename);
	if (!in) {
		error("can't open file");
		return;
	}
	in >> G;
}

VertexList dfs(const Graph& graph, Vertex startVertex){
	VertexList result;
	if (graph.numVertices == 0) {return result;}
	vector<bool> visited(graph.numVertices, false);
	stack<Vertex> s;
	s.push(startVertex);
	while (!s.empty()){
		Vertex v = s.top();
		s.pop();
		if (!visited[v]){
			visited[v] = true;
			result.push_back(v);
			VertexList adjacent = graph.edges_from(v);
			std::reverse(adjacent.begin(), adjacent.end());
			for (Vertex w: graph.edges_from(v)){
			if (!visited[w]){s.push(w);}
			}
		}
	}
	return result;
}

VertexList bfs(const Graph& graph, Vertex startVertex){
	VertexList result;
	if (graph.numVertices == 0) {return result;}
	vector<bool> visited(graph.numVertices, false);
	queue<Vertex> q;
	visited[startVertex] = true;
	q.push(startVertex);
	while (!q.empty()){
		Vertex v = q.front();
		q.pop();
		result.push_back(v);
		for (Vertex w: graph.edges_from(v)){
			if (!visited[w]){
				visited[w] = true;
				q.push(w);
			}
		}
	}
	return result;
}

string get_arg(int argc, char *argv[], string def){
	if (argc > 1) {return std::string(argv[1]);}
	return def;
}

