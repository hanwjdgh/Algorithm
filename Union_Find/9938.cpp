#include <iostream>
#include <ios>

#define MAX 300001

using namespace std;

int par[MAX], gain[MAX];

int find(int n) {
	if (n == par[n])
		return n;
	return par[n] = find(par[n]);
}

void merge(int a, int b) {
	a = find(a);
	b = find(b);
	par[a] = b;
}


int main() {
	cin.tie(NULL);
	cout.tie(NULL);
	ios::sync_with_stdio(false);

	int N, L;
	int a, b;

	cin >> N >> L;

	for (int i = 1; i <= L; i++)
		par[i] = i;

	for (int i = 1; i <= N; i++) {
		cin >> a >> b;

		if (gain[a] == 0) {
			cout << "LADICA" << "\n";
			gain[a] = i;
			merge(a, b);
		}
		else if (gain[b] == 0) {
			cout << "LADICA" << "\n";
			gain[b] = i;
			merge(b, a);
		}
		else if (gain[find(a)] == 0) {
			cout << "LADICA" << "\n";
			gain[find(a)] = i;
			merge(a, b);
		}
		else if (gain[find(b)] == 0) {
			cout << "LADICA" << "\n";
			gain[find(b)] = i;
			merge(b, a);
		}
		else
			cout << "SMECE" << "\n";

	}
	return 0;
}