#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>
#include <functional>  

using namespace std;

vector <int> ro;

int main() {
	int N, W;
	int k = 0;
	
	scanf("%d", &N);
	for (int i = 0; i < N; i++) {
		scanf("%d", &W);
		ro.push_back(W);
	}
	sort(ro.begin(), ro.end(), greater<int>());

	for (int i = 0; i < N; i++) {
		if (k < (ro[i] * (i + 1)))
			k = ro[i] * (i + 1);
	}
	printf("%d\n", k);
	return 0;
}