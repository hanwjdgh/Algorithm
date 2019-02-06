#include <iostream>
#include <ios>
#include <vector>

#define MAX 14

using namespace std;

vector <int > v;
int visit[MAX];
int N;

void find(int n, int cnt) {
	if (n==N && cnt == 6) {
		for (int i = 0; i < N; i++) 
			if (visit[i])
				cout << v[i] << " ";
		cout << "\n";
	}
	if (n == N)
		return;

	visit[n] = 1;
	find(n + 1, cnt + 1);
	visit[n] = 0;
	find(n + 1, cnt);
}

int main() {
	cin.tie(NULL);
	cout.tie(NULL);
	ios::sync_with_stdio(false);

	int num;

	while ((cin >> N) && N != 0) {
		v.clear();
		fill(visit, visit + MAX, 0);

		for (int i = 0; i < N; i++) {
			cin >> num;
			v.push_back(num);
		}

		find(0, 0);
		cout << "\n";
	}

	return 0;
}