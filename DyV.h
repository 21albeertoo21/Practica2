#ifndef DYV_H
#define DYV_H

#include <iostream>
#include <vector>
#include <stdlib.h>

using namespace std;

template <typename T> 

class binary{
	public:
		//ALGORITMO BUSQUEDABINARIA
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
		
		//ALGORITMO QUICKSORT--------------------------------------------------------------
		
		T PartitionLast(vector<T>& v, int ini, int fin){
			T  x = v[fin];
			int i =  ini;
			int aux;
			for(int j = ini; j < fin; j++){
				if(v[j] < x){
					aux = v[i];
					v[i] = v[j];
					v[j] = aux;
					i++;
				}
			}
			aux = v[i];
			v[i] = v[fin];
			v[fin] = aux;
			return i;
			
		}
		
		T PartitionFirst(vector<T>& v, int ini, int fin){
			T x = v[ini];
			int i = ini;
			int aux;
			for(int j = ini; j < fin; j++){
				if(v[j] < x){
					aux = v[i];
					v[i] = v[j];
					v[j] = aux;
					if(i == ini)
						ini = j;
					i++;
				}
			}
			aux = v[i];
			v[i] = v[ini];
			v[ini] = aux;
			return i;
		}
		
		T PartitionMid(vector<T>& v, int ini, int fin){
			int mid = (ini + (fin - ini)) / 2;
			T x = v[mid];
			int i = ini;
			int aux;
			for(int j = ini; j < fin; j++){
				if(v[j] < x){
					aux = v[i];
					v[i] = v[j];
					v[j] = aux;
					if(i == mid)
						mid = j;
					i++;
				}
			}
			aux = v[i];
			v[i] = v[mid];
			v[mid] = aux;
			return i;
		}			
		
		void QuickSortLast(vector<T>& v, int ini, int fin){
			if(ini < fin){
				int pivot = PartitionLast(v, ini, fin);
				QuickSortLast(v, ini, pivot - 1);
				QuickSortLast(v, pivot + 1, fin);
			}
		}
		
		void QuickSortFirst(vector<T>& v, int ini, int fin){
			if(ini < fin){
				int pivot = PartitionFirst(v, ini, fin);
				QuickSortFirst(v, ini, pivot - 1);
				QuickSortFirst(v, pivot + 1, fin);
			}
		}
		
		void QuickSortMid(vector<T>& v, int ini, int fin){
			if(ini < fin){
				int pivot = PartitionMid(v, ini, fin);
				QuickSortMid(v, ini, pivot - 1);
				QuickSortMid(v, pivot + 1, fin);
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
