#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>
#include <queue>

using namespace std;

vector <int> sen;
priority_queue<int> pq;

int main() {
	int N, K;
	int num,sum=0;

	scanf("%d %d", &N, &K);
	for (int i = 0; i < N; i++) {
		scanf("%d", &num);
		sen.push_back(num);
	}
	sort(sen.begin(), sen.end());

	for (int i = 1; i < N; i++){
		if (sen[i] - sen[i - 1] > 0)
			pq.push(sen[i] - sen[i - 1]);
	}
	K--;
	while (K-- && !pq.empty())
		pq.pop();

	while (!pq.empty()){
		sum += pq.top();
		pq.pop();
	}
	printf("%d\n", sum);
	return 0;
}