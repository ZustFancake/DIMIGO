#include <stdio.h>

int main(){
	int T; scanf("%d", &T); // 테스트케이스의 수 
	int score = 0;
	
	for (int _ = 0; _ < T; _++){
		int ans = 1, straight = 0, tangled = 0; // 맨 마지막 줄의 펴져 있는 줄의 수와 꼬인 줄의 수 
		int N, L; scanf("%d %d", &N, &L); // N, L 입력받기 
		int cnt = 0; char c; 
		for (int i = 0; i <= N; i++){
			scanf("%c", &c);
			if      (c == '-') cnt++;
			else if (c == '&') cnt += 3;
		}
		int row = cnt / L;
		int rem = cnt % L;
		
		if (row < 1) ans = -1;
		else{
			for (int i = 0; i < (rem % 3); i++) straight++;
			for (int i = 0; i < (rem / 3); i++) tangled ++;
		}
		
		scanf("%*c");
		
		if (row != 0){ // 출력 결과가 -1이 아닌 경우 
			
			cnt = 0; int stt = 1;
			int sc = 0, st = 0;
			
			while(1){
				char k; scanf("%c", &k);
				if (k == 'e') break;
				if (k != '\n' && (k == '-' || k == '&')){
					cnt++;
					if  (k == '-') sc++;
					else           st++;
				}
				else {
					if (cnt != L){
						if (sc == straight && st == tangled){
							stt = 1;
						}
						else {
							if  ((straight == 0 && st == tangled) || (sc == straight && tangled == 0) || ((straight == 0 && tangled == 0))) stt = 1;
							else                                                                                                            stt = 0;
						}
					}
					cnt = 0; sc = 0; st = 0;
				}
			}
			if (stt == 1) score++;
		}
		else{ // 출력 결과가 -1이여야 하는 경우 
			int n; scanf("%d", &n);
			if (n == -1) score++;
			else {
				while(1){
					char k; scanf("%c", &k);
					if (k == 'e') break;
				}
			}
		}
	}
	
	if      (score == T)             printf("정답입니다.");
	else if (0 < score && score < T) printf("오답입니다. (통과하지 못한 테스트케이스가 있습니다.)");
	else                             printf("오답입니다.");
	
}
