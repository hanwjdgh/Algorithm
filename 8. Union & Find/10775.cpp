#include <iostream>
#include <ios>

#define MAX 100001

using namespace std;

int par[MAX];

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

	int G, P, g;
	int cnt = 0;

	cin >> G >> P;

	for (int i = 0; i <= G; i++)
		par[i] = i;

	for (int i = 1; i <= P; i++) {
		cin >> g;
		
		int temp = find(g);
		if (temp != 0) {
			cnt++;
			merge(temp, temp - 1);
		}
		else
			break;
	}
	cout << cnt << "\n";
	return 0;
}