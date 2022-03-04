#include <iostream>
#include <vector>

int PotenciaNumeroEntero(int p_base, int p_exponente, int p_número);
void PrintTriangulo(int p_baseWidth);
void PrintTriangulo2(int p_baseWidth);
int Factorial(int p_number);
int SumaVector(std::vector<int> p_numbers, int position);

int main() {

		std::vector<int> numbers{ 1,2,3,4,5 };
		std::cout << SumaVector(numbers, 0);

		return 0;
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
