#include <iostream>
#include <algorithm> //para gastar la función min()
#include <vector>

using namespace std;

vector<int> v = {1, 4, 6};
const int TAM = v.size();
const int M = 8;
const int FILAS = 3, COL = 9;

void IniMatriz(int m[][COL]){
	for(int i = 0; i < FILAS; i++){
		for(int j = 0; j < COL; j++){
			m[i][j] = -1;
		}
	}
}

int cambio(vector<int> v, int M){
	int m[FILAS][COL];
	
	IniMatriz(m);
	
	for(int i = 0; i < FILAS; i++)
		m[i][0] = 0;
	
	for(int j = 1; j < M + 1; j++){
        	if(j >= v[0] and m[0][j - v[0]] != -1)
        		m[0][j] = 1 + m[0][j - v[0]];    
    	}
    	
    	for(int i = 1; i < v.size(); i++){
    		m[i][0] = 0;
    		for(int j = 1; j < M + 1; j++){
    			if(j < v[i] or m[i][j - v[i]] == -1)
    				m[i][j] = m[i - 1][j];
    			else if(m[i - 1][j] != -1)
    				m[i][j] = min(m[i - 1][j], 1 + m[i][j - v[i]]);
    			else
    				m[i][j] = 1 + m[i][j - v[i]];
    		}
    	}
    	
    	return m[v.size() -1][M];
    	
}

int main(){
	//vector<int> sol(TAM);
	cout << "La cantidad a devolver es de " << M << " euros" << endl;
	cout << "Las monedas disponibles son las siguientes: ";
	cout << "{";
	int aux = 0;
	for(int i = 0; i < TAM and aux != 1; i++){
		if(i == TAM - 1){
			cout << v[i];
			aux++;
		}
		else
			cout << v[i] << ", ";
	}
	cout << "}" << endl;
	
	int result = cambio(v, M);
	
	cout << "Las monedas minimas para dar el cambio: " << result << endl;
	
	return 0;
}
	
	
	
