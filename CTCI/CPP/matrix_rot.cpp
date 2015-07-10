#include <iostream>
#include <stdlib.h>

using namespace std;

/*
Rotates an N by N matrix 90
degrees counterclockwise
	M pointer to matrix
	N dimension
*/
void rotate(int** M, int N){
		int rotM[N][N];
		int temp;
		for (int i = 0; i <= N/2-1; i++){
			for (int j = 0; j <= (N-1)/2; j++){
				temp = M[i][j];
				M[i][j] = M[j][N-1-i];
				M[j][N-1-i] = M[N-1-i][N-1-j];
				M[N-1-i][N-1-j] = M[N-1-j][i];
				M[N-1-j][i] = temp;
		}
	}
}

/*
Testing
*/
int main(){
	int** array;
	int dim = 3;
	array = (int**) malloc(dim*sizeof(int*));
	for (int i = 0; i < dim; i++){
		array[i] = (int*) malloc(dim*sizeof(int));
	}
	for (int i = 0; i < dim; i++){
		for (int j = 0; j < dim; j++){
			array[i][j] = i*dim+j+1;
		}
	}
	rotate(array, dim);
	for (int i = 0; i < dim; i++){
		for (int j = 0; j < dim; j++){
			cout << array[i][j];
		}
		cout << endl;
	}

}