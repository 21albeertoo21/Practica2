#ifndef DYV_H
#define DYV_H

#include <iostream>
#include <vector>
#include <stdlib.h>

using namespace std;

template <typename T> 

class binary{
	public:
		int BusquedaBinaria(T x, vector<T>& v, int ini, int fin){
			if(ini > fin)
				return -1;
			else{
				int media = (ini + fin) / 2;
				if(v[media] == x)
					return media;
				else if(v[media] > x)
					return BusquedaBinaria(x, v, ini, media - 1);
				else
					return BusquedaBinaria(x, v, media + 1, fin);
			}
		}
		
		int BusquedaBinariaINV(T x, vector<T>& v, int ini, int fin){
			if(ini > fin)
				return -1;
			else{
				int media = (ini + fin) / 2;
				if(v[media] == x)
					return media;
				else if(v[media] > x)
					return BusquedaBinariaINV(x, v, media + 1, fin);
				else
					return BusquedaBinariaINV(x, v, ini, media - 1);
			}
		}
		
		T Partition(vector<T>& v, int ini, int fin){
			int x = v[fin];
			int i =  ini;
			int aux;
			for(int j = ini; j < fin; j++){
				if(v[j] <= x){
					int aux = v[i];
					v[i] = v[j];
					v[j] = aux;
					i = i + 1;
				}
			}
			aux = v[i];
			v[i] = v[fin];
			v[fin] = aux;
			return i;
			
		}
		void QuickSort(vector<T>& v, int ini, int fin){
			if(ini < fin){
				int pivot = Partition(v, ini, fin);
				QuickSort(v, ini, pivot - 1);
				QuickSort(v, pivot + 1, fin);
			}
		}
		
		void Print(vector<T>& v, T size){
			cout << "[ ";
			for(int i = 0; i < size; i++)
				cout << v[i] << " ";
			cout << "]" << endl;
		}
		
		
};


#endif	
