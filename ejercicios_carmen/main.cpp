#include <iostream>
#include <vector>
#include "SparceGraph.h"

int PotenciaNumeroEntero(int p_base, int p_exponente, int p_número);
void PrintTriangulo(int p_baseWidth);
void PrintTriangulo2(int p_baseWidth);
int Factorial(int p_number);
int SumaVector(std::vector<int> p_numbers, int position);

int main() {

	SparseGraph graph = new SparseGraph(true);
	
	for (int i = 0; i < 6; i++) {
		NavigationGraphNode node = NavigationGraphNode(Vector2D<float>(1, 1));
		node.SetIndex(i);
		graph.AddNode(node);
	}

	graph.AddEdge(GraphEdge(4,1));
	graph.AddEdge(GraphEdge(1,4));
	graph.AddEdge(GraphEdge(1,0));
	graph.AddEdge(GraphEdge(0,1));
	graph.AddEdge(GraphEdge(0,2));
	graph.AddEdge(GraphEdge(2,0));
	graph.AddEdge(GraphEdge(2,3));
	graph.AddEdge(GraphEdge(3,2));
	graph.AddEdge(GraphEdge(3,4));
	graph.AddEdge(GraphEdge(4,3));
	graph.AddEdge(GraphEdge(4,5));
	graph.AddEdge(GraphEdge(5,4));
	graph.AddEdge(GraphEdge(3,5));
	graph.AddEdge(GraphEdge(5,3));

	for (int i = 0; i < 6; i++) {
		GraphEdge edge = graph.GetEdge(1, 4);
		std::cout << edge.GetDestinationNodeIndex() << std::endl;
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
