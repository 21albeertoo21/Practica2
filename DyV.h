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
			if(ini > fin){
				cout << "El valor " << x << " no se encuentra en el array\n"; 
				return -1;
			}
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
			if(ini > fin){
				cout << "El valor " << x << "no se encuentra en el array\n";
				return -1;
			}
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
		
		void Print(vector<T>& v, T size){
			cout << "[ ";
			for(int i = 0; i < size; i++)
				cout << v[i] << " ";
			cout << "]" << endl;
		}
};


#endif	
