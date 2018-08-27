#include <iostream>
#include <ios>
#include <cmath>

#define MAX 20001

using namespace std;

int par[MAX], dis[MAX];

int find(int n) {
	if (n == par[n])
		return n;
	int temp = find(par[n]);
	dis[n] += dis[par[n]];
	par[n] = temp;
	return temp;
}

void merge(int a, int b) {
	par[a] = b;
	dis[a] = abs(b-a) % 1000;
}

int main() {
	cin.tie(NULL);
	cout.tie(NULL);
	ios::sync_with_stdio(false);

	int T, N, a, b;
	char t;

	cin >> T;

	while (T--) {	
		cin >> N;

		for (int i = 1; i <= N; i++) {
			par[i] = i;
			dis[i] = 0;
		}

		while (1) {	

			cin >> t;

			if (t == 'E') {
				cin >> a;
				find(a);
				cout << dis[a] << "\n";
			}
			else if (t == 'I') {
				cin >> a >> b;
				merge(a, b);
			}
			else
				break;
		}
	}
	return 0;
}