#include <iostream>
#include <ios>

#define MAX 201

using namespace std;

int par[MAX];
int arr[MAX][MAX];

int find(int n) {
	if (n == par[n])
		return n;
	else
		return par[n] = find(par[n]);
}

void merge(int a, int b) {
	a = find(a);
	b = find(b);
	par[b] = a;
}

int main() {
	cin.tie(NULL);
	cout.tie(NULL);
	ios::sync_with_stdio(false);

	int N, M, num;

	cin >> N >> M;

	for (int i = 1; i <= N; i++) 
		for (int j = 1; j <= N; j++) 
			cin >> arr[i][j];

	for (int i = 1; i <= N; i++)
		par[i] = i;

	for (int i = 1; i <= N; i++) 
		for (int j = i + 1; j <= N; j++) 
			if (arr[i][j] == 1) 
				merge(i, j);

	int temp = 0, chk=1;
	for (int i = 0; i < M; i++) {
		cin >> num;
		if (i == 0)
			temp = find(num);
		else {
			if (temp != find(num))
				chk = 0;
		}
	}
	if (chk == 0)
		cout << "NO" << "\n";
	else
		cout << "YES" << "\n";
	return 0;
}