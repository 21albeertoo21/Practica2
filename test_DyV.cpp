#include <iostream>
#include <vector>
#include "DyV.h"

int main(){
	binary<int> clase1;
	binary<char> clase2;
	
	vector<int> a{0, 3, 7, 9, 12};
	vector<char> b{'a', 'b', 'c', 'd', 'j'};
	vector<int> c{12, 9, 7, 3, 0}; 
	
	cout << "Vector de ints:" << endl;
	clase1.Print(a, a.size());
	clase1.Print(c, c.size());
	int resultado1 = clase1.BusquedaBinaria(12, a, 0, a.size() - 1);
	int resultado_inv = clase1.BusquedaBinaria(12, c, 0, c.size() - 1);
	cout << "El número 12 se encuentra en la posición-> " << resultado1 << endl << endl;
	cout << "El número 12 se encuentra en la posición-> " << resultado_inv << endl << endl;
	
	cout << "Vector de chars:" << endl;
	clase2.Print(b, b.size());
	int resultado2 = clase2.BusquedaBinaria('c', b, 0, b.size() - 1);
	cout << "La letra 'c' se encuentra en la posición-> " << resultado2 << endl << endl;
	
	return 0;	
}
