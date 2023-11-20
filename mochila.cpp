#include <iostream>
#include <math.h>
#include <vector>

#define ROW 4
#define COL 16

using namespace std;

void inicializar_matriz(int m[ROW][COL]){
	
	for(int i = 0; i < ROW; i++){
		for(int j = 0; j < COL; j++){
				m[i][j] = -1;
		}
	}
	for(int i = 0; i < ROW; i++)
		m[i][0] = 0;
	for(int j = 0; j < COL; j++)
		m[0][j] = 0;
}

void print_m(int m[ROW][COL]){
	for(int i = 0; i < ROW; i++){
		for(int j = 0; j < COL; j++)
			cout << m[i][j] << " ";
		cout << endl;
	}
}

int mochila(vector<int>& p, vector<int>& b, int M, vector<int>& sol, int N){
	int matriz[ROW][COL];
	inicializar_matriz(matriz);
	
	for(int i = 1; i < ROW; i++){
		for(int j = 1; j < COL; j++){
			if(j - p[i - 1] < 0)
				matriz[i][j] = matriz[i - 1][j];
			else
				matriz[i][j] = max(matriz[i - 1][j], matriz[i - 1][j - p[i - 1]] + b[i - 1]);
		}
	}
	int j = 15;
	for(int i = 3; i >= 0; i--){
		if(matriz[i][j] != matriz[i-1][j])
			sol[i] = 1;
	}
	
	print_m(matriz);
	int resultado = matriz[ROW - 1][COL - 1];
	return resultado;
}

int main(){
	vector<int> p = {9, 6, 5}; //peso
	vector<int> b = {38, 40, 24}; //beneficio
	int M = 15; //peso mochila
	int N = p.size();
	vector<int> sol = {0, 0, 0};
	
	int result = mochila(p, b, M, sol, N);
	cout << "Beneficio maximo: " << result << endl;
	cout << "Vector solucion: " << "{ ";
	for(int i = 0; i < N; i++)
		cout << sol[i] << " ";
	cout << "}";
	return 0;
}


