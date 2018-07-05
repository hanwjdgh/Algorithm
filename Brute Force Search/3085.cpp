#include <stdio.h>
#include <algorithm>
using namespace std;

int dx[] = { 0,1 };
int dy[] = { 1,0 };

int N, result;
char arr[51][51];

int count() {
	int max_val = 1, cnt = 1;
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j < N; j++) {
			if (arr[i][j] == arr[i][j + 1])
				cnt++;
			else {
				max_val = max(max_val, cnt);
				cnt = 1;
			}
		}
		max_val = max(max_val, cnt);
		cnt = 1;
		
		for (int j = 1; j < N; j++) {
			if (arr[j][i] == arr[j + 1][i])
				cnt++;
			else {
				max_val = max(max_val, cnt);
				cnt = 1;
			}
		}
		max_val = max(max_val, cnt);
		cnt = 1;
	}
	return max_val;
}

int main() {
	scanf("%d%*c", &N);
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= N; j++) {
			scanf("%c", &arr[i][j]);
		}
		getchar();
	}

	for (int x = 1; x <= N; x++) {
		for (int y = 1; y <= N; y++) {
			for (int k = 0; k < 2; k++) {
				int nx = x + dx[k], ny = y + dy[k];
				if (nx > N || ny > N)
					continue;
				swap(arr[x][y], arr[nx][ny]);
				result = max(result, count());
				swap(arr[x][y], arr[nx][ny]);
			}
		}
	}
	printf("%d", result);
	return 0;
}