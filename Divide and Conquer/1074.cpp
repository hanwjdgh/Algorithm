#include <iostream>
#include <cstdio>
#include <cmath>

using namespace std;

int N, r, c;
int cnt = 0;

void find(int s, int f, int n) {
	if (s == r && f == c) {
		printf("%d", cnt);
		return;
	}

	if (r < s + n && r >= s && c < f + n && c >= f) {
		n /= 2;
		for (int i = 0; i < 2; i++) {
			for (int j = 0; j < 2; j++)
				find(s + i*n, f + j*n, n);
		}
	}
	else 
		cnt += n*n;
}

int main() {
	cin >> N >> r >> c;

	find(0, 0, (int)pow(2, N));

	return 0;
}