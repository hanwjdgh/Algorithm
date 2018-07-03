#include <iostream>
#include <cstdio>

using namespace std;

int main() {
	int N,temp,sum;
	int cnt=0,i;
	scanf("%d", &N);

	for (i = 1; i <= N; i++) {
		sum = i;
		temp = i;
		while (temp > 0) {
			sum += temp % 10;
			temp /= 10;
		}
		if (sum == N) {
			cnt = 1;
			break;
		}
	}
	if (cnt == 1)
		printf("%d",i);
	else
		printf("0");
	return 0;
}