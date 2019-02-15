#include <iostream>
#include <cstdio>

using namespace std;

char arr[64][64];

void find(int s, int f, int n) {
	char c = arr[s][f];
	bool error = false;

	for (int i = s; i < s + n; i++) {
		for (int j = f; j < f + n; j++) {
			if (arr[i][j] != c) {
				error = !error;
				break;
			}
		}
		if (error)
			break;
	}
	if (!error) {
		printf("%c", c);
		return;
	}
	n /= 2;
	printf("(");
	for (int i = 0; i < 2; i++) {
		for (int j = 0; j < 2; j++)
			find(s+i*n,f+j*n,n);
	}
	printf(")");
}

int main() {
	int N;
	
	cin >> N;
	for (int i = 0; i < N; i++) 
		cin >> arr[i];
	
	find(0, 0, N);
	return 0;
}