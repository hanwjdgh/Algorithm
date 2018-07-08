#include <iostream>
#include <cstdio>
#include <algorithm>

using namespace std;

char DNA[1000][50];

int main() {
	int N, M;
	int ham = 0;
	char d[4] = {'A','C','G','T'};

	scanf("%d %d", &N, &M);
	for (int i = 0; i < N; i++) 
		scanf("%s", DNA[i]); getchar();
	
	for (int i = 0; i < M; i++) {
		int ar[4] = { 0, };
		for (int j = 0; j < N; j++) {
			switch (DNA[j][i]){
			case 'A':
				ar[0]++;
				break;
			case 'C':
				ar[1]++;
				break;
			case 'G':
				ar[2]++;
				break;
			case 'T':
				ar[3]++;
				break;
			default:
				break;
			}
		}
		int max = 0;
		char t;
		for (int i = 0; i < 4; i++) {
			if (max < ar[i]) {
				max = ar[i];
				t = d[i];
			}
		}
		ham += (N - max);
		printf("%c", t);
	}
	printf("\n%d\n", ham);
	return 0;
}