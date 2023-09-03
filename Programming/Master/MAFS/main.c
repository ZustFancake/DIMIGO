#include <stdio.h>
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

int main() {
    int N;
    scanf("%d", &N);

    int A[N][N];
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            A[i][j] = 0;
        }
    }
    int num = 1;
    int x = 0, y = 0, direction = 1;

    for (int i = 0; i < N * N; i++) {
        A[x][y] = num++;
        if (direction == 1) {
            if (x == N - 1 || A[x + 1][y] != 0) {
                direction = 2;
                y++;
            } else {
                x++;
            }
        } else if (direction == 2) {
            if (y == N - 1 || A[x][y + 1] != 0) {
                direction = 3;
                x--;
            } else {
                y++;
            }
        } else if (direction == 3) {
            if (x == 0 || A[x - 1][y] != 0) {
                direction = 4;
                y--;
            } else {
                x--;
            }
        } else if (direction == 4) {
            if (y == 0 || A[x][y - 1] != 0) {
                direction = 1;
                x++;
            } else {
                y--;
            }
        }
    }

    for (int row = 0; row < N; row++) {
        for (int col = 0; col < N; col++) {
            if (is_prime(A[row][col]) == 1) {
                A[row][col] = 1;
            } else {
                A[row][col] = 0;
            }
        }
    }

    int p, q;
    scanf("%d %d", &p, &q);

    for (int i = 0; i < q; i++) {
        for (int j = 0; j < p; j++) {
            scanf("%d", &B[i][j]);
        }
    }

    int R = 0;

    for (int i = 0; i <= N - q; i++) {
        for (int j = 0; j <= N - p; j++) {
            int match = 1;
            for (int r = 0; r < q; r++) {
                for (int c = 0; c < p; c++) {
                    if (A[i + r][j + c] != B[r][c]) {
                        match = 0;
                        break;
                    }
                }
                if (!match) {
                    break;
                }
            }
            if (match) {
                R++;
            }
        }
    }

    printf("%d", R);

    return 0;
}
