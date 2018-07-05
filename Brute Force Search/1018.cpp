#include <iostream>
#include <cstdio>
#include <algorithm>

using namespace std;

int main() {
	int M, N;
	char arr[51][51];
	scanf("%d %d", &N, &M); 
	getchar();
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++)
			scanf("%c", &arr[i][j]);
		getchar();
	}

	int result = 64;
	for (int i = 0; i <= N - 8; i++) {
		for (int j = 0; j <= M - 8; j++) {
			int cnt = 0;
			for (int a = 0; a < 8; a++)
				for (int b = 0; b < 8; b++)
					cnt += (a % 2 == b % 2 ? 'W' : 'B') == arr[i + a][j + b];
			result = min(result, cnt);
			result = min(result, 64 - cnt);
		}
	}
	printf("%d\n", result);
}