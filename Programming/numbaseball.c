#include <stdio.h>
#include <stdlib.h>
#include <math.h>

/* 이 코드는 색상을 사용하기 위해 범위 밖의 내용을 활용했습니다. */
#define COLOR_RED	"\033[1;38;2;255;0;0m"
#define COLOR_GREEN	"\033[1;38;2;0;255;0m"
#define COLOR_YELLOW	"\033[1;38;2;255;255;0m"
#define COLOR_RESET	"\033[1;38;2;255;255;255m"
/* 이 코드는 색상을 사용하기 위해 범위 밖의 내용을 활용했습니다. */

int power(int a, int b) {
	if (b == 0) return 1;
	int result = 1;
	for (int i = 0; i < b; i++) result *= a;
	return result;
}

int haveSameDigits(int num) {
	int digits[10] = {0};
	
	while (num > 0) {
		int digit = num % 10; digits[digit]++; num /= 10;
	}

	for (int i = 0; i < 10; i++) if (digits[i] >= 2) return 1;
	return 0;
}

int getnum(int digit){
	int t = 0;
	for (int i = 0; i < digit; i++) t += 9 * power(10, i);
	int k = (int)rand() % (t - power(10, digit - 1) + 1) + power(10, digit - 1);
	return haveSameDigits(k) ? getnum(digit) : k;
}

int doContainNum(int num, int dst, int dgt){
	for (int d = 0; d < dgt; d++){
		if (num % 10 == dst) return 1;
		num /= 10;
	}
	return 0;
}

int getPosOf(int num, int dst, int dgt){
	for (int d = 0; d < dgt; d++){
		if (num % 10 == dst) return d;
		num /= 10;
	}
	return -1;
}

int getScore(int in, int num, int dgt){
	int S = 0, B = 0, in_org = in;
	
	for (int d = 0; d < dgt; d++){
		if (in % 10 == num % 10) S++;
		else if (doContainNum(in_org, num % 10, dgt)) B++;
		in /= 10; num /= 10;
	}
	
	return S == dgt ? -1 : S * 10 + B;
}

void parseScore(int score){
	if (score / 10 > 0) printf(COLOR_GREEN "%d스트라이크" COLOR_RESET, score / 10);
	if (score / 10 > 0 && score % 10 > 0) printf(" ");
	if (score % 10 > 0) printf(COLOR_YELLOW "%d볼" COLOR_RESET, score % 10);
	if (score % 10 == 0 && score / 10 == 0) printf(COLOR_RED "OUT" COLOR_RESET);
	/* 이 코드는 색상을 사용하기 위해 범위 밖의 내용을 활용했습니다. */
}

void printJeopmisaForNum(int num){
	switch (num % 10){
		case 0:
		case 1:
		case 3:
		case 6:
		case 7:
		case 8: printf("을"); break;
		default: printf("를"); break;
	}
}

void yeotTwoYeot(int num){
	switch (num % 10){
		case 0:
		case 1:
		case 3:
		case 6:
		case 7:
		case 8: printf("이"); break;
		default: break;
	}
}

int main() {
	srand(time(NULL)); printf("\n");
	printf("┌─────────────┐\n");
	printf("│　숫자 야구　│\n");
	printf("└─────────────┘\n\n");
	printf("$ 자릿수를 고르면 겹치는 숫자가 없는 수가 무작위하게 선택됩니다. 숫자는 10진수이고 [0-9]로만 구성됩니다.\n");
	printf("$ 자리와 숫자가 모두 맞으면 %s스트라이크%s, 자리는 맞지 않지만 숫자가 선택된 수에 포함되는 경우는 %s볼%s입니다.\n",
	                                                        COLOR_GREEN, COLOR_RESET, COLOR_YELLOW, COLOR_RESET);
	printf("$ 주어지는 정보를 이용해서 숫자를 맞히세요.\n\n");
	printf("$ 게임 중 입력되는 숫자의 자릿수와 선택한 자릿수가 일치하지 않으면 입력은 무시되므로 주의하세요.\n");
	printf("$ -1을 입력하면 기권 처리됩니다. 또한, 시도 횟수는 무제한입니다.\n\n");
	
	int digit = 0;
	while (!(2 <= digit && digit <= 9)){
		printf("자릿수를 입력하세요. (2 - 9)\nroot@server:~# "); scanf("%d", &digit);
		if (!(2 <= digit && digit <= 9)) digit = 0; printf("\n");
	}
	
	int r = getnum(digit), try = 0, d;
	
	while (1) {
		try++; printf("%d번째 시도입니다. %d자리 숫자를 입력하세요.\nroot@server:~# ", try, digit); scanf("%d", &d);
		if (d == -1){
			printf("게임을 포기했습니다. 선택된 숫자는 %d", r); yeotTwoYeot(r); printf("였습니다."); break;
		}
		if (floor(log10(abs(d))) + 1 != digit) continue;
		if (getScore(d, r, digit) == -1){
			printf("축하합니다! %d번의 시도로 선택된 숫자 %d", try, r); printJeopmisaForNum(r); printf(" 맞혔습니다."); break;
		}
		else{
			parseScore(getScore(d, r, digit)); printf("입니다.\n\n");
		}
	}
	
	return 0;
}
