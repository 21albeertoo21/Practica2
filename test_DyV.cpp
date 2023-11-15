#include <iostream>
#include <vector>
#include "DyV.h"
#include <chrono>

int main(){
	binary<int> clase1;
	binary<char> clase2;
	
	vector<int> a{0, 3, 7, 9, 12};
	vector<char> b{'a', 'b', 'c', 'd', 'j'};
	vector<int> c{12, 9, 7, 3, 0};
	vector<int> d{1, 3, 2, 0, 5, 40}; 
	
	//BÚSQUEDA BINARIA __________________________________
	
	cout << "Vector de ints:" << endl;
	clase1.Print(a, a.size());
	int resultado1 = clase1.BusquedaBinaria(12, a, 0, a.size() - 1);
	cout << "El número 12 se encuentra en la posición-> " << resultado1 << endl << endl;
	
	clase1.Print(c, c.size());
	int resultado_inv = clase1.BusquedaBinariaINV(12, c, 0, c.size() - 1);
	cout << "El número 12 se encuentra en la posición-> " << resultado_inv << endl << endl;
	
	cout << "Vector de chars:" << endl;
	clase2.Print(b, b.size());
	int resultado2 = clase2.BusquedaBinaria('c', b, 0, b.size() - 1);
	cout << "La letra 'c' se encuentra en la posición-> " << resultado2 << endl << endl;
	
	//QUICKSORT ____________________________________________
	
	//PIVOTE EN ÚLTIMO ELEMENTO
	std::cout << "Antes de ordenar el array\n";
	clase1.Print(d, d.size());
	
	auto start = std::chrono::system_clock::now();
	clase1.QuickSortLast(d, 0, d.size() - 1);
	auto end = std::chrono::system_clock::now();
	
	std::chrono::duration<float, std::milli> duration = end - start;
	
	std::cout << "\nDespués de ordenarlo\n";
	clase1.Print(d, d.size());
	std::cout << "Tiempo con pivote en último elemento: " << duration.count() << "s\n" << std::endl;
	
	//PIVOTE EN EL PRIMER ELEMENTO
	vector<int> e{1, 3, 2, 0, 5, 40}; 
	std::cout << "Antes de ordenar el array\n";
	clase1.Print(e, e.size());
	
	auto start1 = std::chrono::system_clock::now();
	clase1.QuickSortFirst(e, 0, e.size() - 1);
	auto end1 = std::chrono::system_clock::now();
	
	std::chrono::duration<float, std::milli> duration1 = end1 - start1;
	
	std::cout << "\nDespués de ordenarlo\n";
	clase1.Print(e, e.size());
	std::cout << "Tiempo con pivote en primer elemento: " << duration1.count() << "s\n" << std::endl;
	
	//PIVOTE EN EL ELEMENTO NEUTRO
	vector<int> f{1, 3, 2, 0, 5, 40}; 
	std::cout << "Antes de ordenar el array\n";
	clase1.Print(f, f.size());
	
	auto start2 = std::chrono::system_clock::now();
	clase1.QuickSortMid(f, 0, f.size() - 1);
	auto end2 = std::chrono::system_clock::now();
	
	std::chrono::duration<float, std::milli> duration2 = end2 - start2;
	
	std::cout << "\nDespués de ordenarlo\n";
	clase1.Print(f, f.size());
	std::cout << "Tiempo con pivote en el medio: " << duration2.count() << "s" << std::endl;
	
	
	return 0;	
}
