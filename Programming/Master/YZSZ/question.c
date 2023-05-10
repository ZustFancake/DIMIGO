#include <stdio.h>

int main(){
	int N, L; scanf("%d %d", &N, &L); // N, L을 입력받기
	int cnt = 0; char c;
	for (int i = 0; i <= N; i++){
		scanf("%c", &c);
		if (c == '-') cnt++;
		else if (c == '&') cnt += 3;
	}
	int row = cnt / L;
	int rem = cnt % L;
	
	if (row < 1) printf("-1");
	else{
		for (int i = 0; i < row; i++){
			for (int j = 0; j < L; j++){
				printf("-");
			}
			printf("\n");
		}
		for (int i = 0; i < (rem % 3); i++) printf("-");
		for (int i = 0; i < (rem / 3); i++) printf("&");
	}
}
