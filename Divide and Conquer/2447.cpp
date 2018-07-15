#include <iostream>
#include <cstdio>
#include <vector>

using namespace std;

vector <vector<char> > v;

void fill(int s, int f, int n) {
	if (n == 1) {
		v[s][f] = '*';
		return;
	}
	n /= 3;
	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < 3; j++) {
			if (i == 1 && j == 1)
				continue;
			fill(s + i*n, f + j*n, n);
		}
	}

}

int main(void) {
	int N;

	cin >> N;
	for (int i = 0; i < N; i++) {
		vector <char> tmp;
		for (int j = 0; j < N; j++)
			tmp.push_back(' ');
		v.push_back(tmp);
	}

	fill(0, 0, N);

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++)
			cout << v[i][j];
		cout << endl;
	}
	return 0;
}