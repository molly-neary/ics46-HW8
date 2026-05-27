#include "graph.h"
#include <iostream>

int main(int argc, char *argv[]) {

//small

	std::cout << "small.txt" << std::endl;

    string filename1 = get_arg(argc, argv, "src/small.txt");
    Graph G1;
    file_to_graph(filename1, G1);

    cout << "MST: ";
    EdgeList mst1 = Kruskals(G1);
    cout << mst1 << endl;
    cout << "Total weight = " << sum_weights(mst1) << endl;

    cout << "DFS traversal: ";
    cout << dfs(G1, 0) << endl;

    cout << "BFS traversal: ";
    cout << bfs(G1, 0) << endl;

	std::cout<< " " << std::endl;

//medium

	std::cout << "medium.txt" << std::endl;

	string filename2 = get_arg(argc, argv, "src/medium.txt");
    Graph G2;
    file_to_graph(filename2, G2);

    cout << "MST: ";
    EdgeList mst2 = Kruskals(G2);
    cout << mst2 << endl;
    cout << "Total weight = " << sum_weights(mst2) << endl;

    cout << "DFS traversal: ";
    cout << dfs(G2, 0) << endl;

    cout << "BFS traversal: ";
    cout << bfs(G2, 0) << endl;

	std::cout<< " " << std::endl;

//large

	std::cout << "large.txt" << std::endl;

	string filename3 = get_arg(argc, argv, "src/large.txt");
    Graph G3;
    file_to_graph(filename3, G3);

    cout << "MST: ";
    EdgeList mst3 = Kruskals(G3);
    cout << mst3 << endl;
    cout << "Total weight = " << sum_weights(mst3) << endl;

    cout << "DFS traversal: ";
    cout << dfs(G3, 0) << endl;

    cout << "BFS traversal: ";
    cout << bfs(G3, 0) << endl;

	std::cout<< " " << std::endl;


//largest

std::cout << "largest.txt" << std::endl;


	string filename4 = get_arg(argc, argv, "src/largest.txt");
    Graph G4;
    file_to_graph(filename4, G4);

    cout << "MST: ";
    EdgeList mst4 = Kruskals(G4);
    cout << mst4 << endl;
    cout << "Total weight = " << sum_weights(mst4) << endl;

    cout << "DFS traversal: ";
    cout << dfs(G4, 0) << endl;

    cout << "BFS traversal: ";
    cout << bfs(G4, 0) << endl;

	std::cout<< " " << std::endl;

}
