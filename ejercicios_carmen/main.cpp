#include <iostream>
#include <vector>
#include <list>
#include "GraphSearchDFS.h"

int PotenciaNumeroEntero(int p_base, int p_exponente, int p_número);
void PrintTriangulo(int p_baseWidth);
void PrintTriangulo2(int p_baseWidth);
int Factorial(int p_number);
int SumaVector(std::vector<int> p_numbers, int position);

int main() {

	SparseGraph graph = new SparseGraph(true);
	
	for (int i = 0; i < 13; i++) {
		NavigationGraphNode node = NavigationGraphNode(Vector2D<float>(1, 1));
		node.SetIndex(i);
		graph.AddNode(node);
	}

	graph.AddEdge(GraphEdge(1,0));
	graph.AddEdge(GraphEdge(0,1));
	graph.AddEdge(GraphEdge(0,2));
	graph.AddEdge(GraphEdge(2,0));
	graph.AddEdge(GraphEdge(2,9));
	graph.AddEdge(GraphEdge(9,2));
	graph.AddEdge(GraphEdge(9,3));
	graph.AddEdge(GraphEdge(3,9));
	graph.AddEdge(GraphEdge(0,8));
	graph.AddEdge(GraphEdge(8,0));
	graph.AddEdge(GraphEdge(8,12));
	graph.AddEdge(GraphEdge(12,8));
	graph.AddEdge(GraphEdge(12,7));
	graph.AddEdge(GraphEdge(7,12));
	graph.AddEdge(GraphEdge(3,11));
	graph.AddEdge(GraphEdge(11,3));
	graph.AddEdge(GraphEdge(11,6));
	graph.AddEdge(GraphEdge(6,11));
	graph.AddEdge(GraphEdge(6,4));
	graph.AddEdge(GraphEdge(4,6));
	graph.AddEdge(GraphEdge(4,10));
	graph.AddEdge(GraphEdge(10,4));
	graph.AddEdge(GraphEdge(5,4));
	graph.AddEdge(GraphEdge(4,5));

	GraphSearchDFS graphSearch = GraphSearchDFS(graph, 10, 1);
	graphSearch;

	if (graphSearch.IsFound()) {
			std::vector<int> pathToTarget = graphSearch.GetPathToTarget();
			for (int i = 0; i < pathToTarget.size(); i++) {
					std::cout << pathToTarget[i] << std::endl;
			}
	}

}

int PotenciaNumeroEntero(int p_base, int p_exponente, int p_numero) {

		if (p_exponente == 0) { return p_base; }
		if (p_exponente == 1) { return p_numero; }
		return PotenciaNumeroEntero(p_base, p_exponente - 1, p_base * p_numero);

}

void PrintTriangulo(int p_baseWidth) {
		if (p_baseWidth == 0) { return; }
		for (int i = 0; i < p_baseWidth; i++) {
				std::cout << "*";
		}
		std::cout << std::endl;
		PrintTriangulo(p_baseWidth - 1);

}

void PrintTriangulo2(int p_baseWidth) {
		if (p_baseWidth == 0) { return; }
		PrintTriangulo2(p_baseWidth - 1);
		for (int i = 0; i < p_baseWidth; i++) {
				std::cout << "*";
		}
		std::cout << std::endl;
}

int Factorial(int p_number) {
		if (p_number == 0) { return 1; }
		return p_number * Factorial(p_number - 1);
}

int SumaVector(std::vector<int> p_numbers, int position) {
		if (position == p_numbers.size() - 1) { return p_numbers[p_numbers.size() - 1]; }
		return p_numbers[position] + SumaVector(p_numbers, position + 1);
}
