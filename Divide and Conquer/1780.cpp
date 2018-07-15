#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>

using namespace std;

vector <vector<int> > v;
int cnt[3] = { 0, };

void find(int s, int f, int n) {
	int val = v[s][f];
	bool error = false;

	for (int i = s; i < s + n; i++) {
		for (int j = f; j < f + n; j++) {
			if (v[i][j] != val) {
				error = !error;
				break;
			}
		}
		if (error)
			break;
	}
	if (!error) {
		cnt[val + 1]++;
		return;
	}
	n /= 3;
	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < 3; j++)
			find(s+i*n,f+j*n,n);
	}
}

int main() {
	int N, num;

	cin >> N;

	for (int i = 0; i < N; i++) {
		vector <int> tmp;
		for (int j = 0; j < N; j++) {
			cin >> num;
			tmp.push_back(num);
		}
		v.push_back(tmp);
	}

	find(0, 0, N);

	for (int i = 0; i < 3; i++)
		printf("%d\n", cnt[i]);
	return 0;
}