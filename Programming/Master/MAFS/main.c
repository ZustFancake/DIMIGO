#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

int is_prime(int n) { 
    if (n < 2) {
        return 0;
    }
    for (int i = 2; i <= sqrt(n); i++) {
        if (n % i == 0) { 
            return 0;
        }
    }
    return 1;
}

int** S(int n) {
    int** matrix = (int**)malloc(n * sizeof(int*));
    for (int i = 0; i < n; i++) {
        matrix[i] = (int*)malloc(n * sizeof(int));
    }
    
    for (int row = 0; row < n; row++){
    	for (int col = 0; col < n; col++){
    		matrix[row][col] = 0;
		}
	}
	
	int x, y = 0;
	int num = 1;
	int direction = 1;
	
	for (int _ = 0; _ < pow(n, 2); _++){
		matrix[x][y] = num; num++;
		if (direction == 1){
			if ((x == n - 1) || (matrix[x + 1][y] != 0)){
				direction = 2; y++;
			}
			else x++;
		}
		else if (direction == 2){
			if ((y == n - 1) || (matrix[x][y + 1] != 0)){
				direction = 3; x--;
			}
			else y++;
		}
		else if (direction == 3){
			if ((x == 0) || (matrix[x - 1][y] != 0)){
				direction = 4; y--;
			}
			else x--;
		}
		else if (direction == 4){
			if ((y == 0) || (matrix[x][y - 1] != 0)){
				direction = 1; x++;
			}
			else y--;
		}	
	} ;
	
	for (int row = 0; row < n; row++){
		for (int col = 0; col < n; col++){
			if (is_prime(matrix[row][col]) == 1) matrix[row][col] = 1;
			else                                 matrix[row][col] = 0;
		}
	}
    
    return matrix;
}

int* str_to_int_array(char* input, int len){
	int* arr = (int*)malloc(len * sizeof(int));
	char *tok = strtok(input, " "); int i = 0;
    while (tok != NULL) {
        arr[i++] = atoi(tok);
        tok = strtok(NULL, " ");
    }
    
    return arr;
}

int compare(int** P, int** Q, int p, int q){
	for (int _q = 0; _q < q; _q++){
		for (int _p = 0; _p < p; _p++){
			if (P[_q][_p] != Q[_q][_p]) return 0;
		}
	};
	return 1;
}

int main(){
	int N; scanf("%d", &N);
	int** A = S(N);
	
	int p, q; scanf("%d %d", &p, &q);
	int** M = (int**)malloc(q * sizeof(int*));
    for (int i = 0; i < q; i++) {
        M[i] = (int*)malloc(p * sizeof(int));
    }
    
    int i = 0;
    while (i < q + 1){
    	char input[3999]; fgets(input, sizeof(input), stdin);
        M[i - 1] = str_to_int_array(input, p);
        i++;
    }
	
	int R = 0;
	
	for (int row = 0; row <= N - q; row++){
		for (int col = 0; col <= N - p; col++){
			int** m = (int**)malloc(q * sizeof(int*));
			for (int i = 0; i < q; i++) {
		        m[i] = (int*)malloc(p * sizeof(int));
		    }
		    
		    int r = 0;
		    for (int i = row; i < row + q ; i++){
		    	int c = 0;
		    	for (int j = col; j < col + p; j++){
		    		m[r][c] = A[i][j]; c++;
				}
				r++;
			}
			
			if (compare(m, M, p, q) == 1) R++;
		}
	}
	
	printf("%d", R);
	
	free(A); return 0;
}
