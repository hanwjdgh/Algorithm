#include <iostream>
#include <ios>
#include <string>
#include <vector>

#define MAX 1000001

using namespace std;

int fail[MAX];
vector <int > v;

int main() {
	cin.tie(NULL);
	cout.tie(NULL);
	ios::sync_with_stdio(false);
	
	string T, P;
	int N, M;

	getline(cin, T);
	getline(cin, P);

	N = T.length();
	M = P.length();

	for (int i = 1, j = 0; i<M; i++) {
		while (j > 0 && P[i] != P[j]) 
			j = fail[j - 1];
		if (P[i] == P[j]) 
			fail[i] = ++j;
	}

	for (int i = 0, j = 0; i < N; i++) {
		while (j > 0 && T[i] != P[j]) 
			j = fail[j - 1];
		if (T[i] == P[j]) {
			if (j == M - 1) {
				v.push_back(i - M + 2);
				j = fail[j];
			}
			else
				j++;
		}
	}

	cout << v.size() << "\n";
	for (auto i : v)
		cout << i << " ";
	cout << "\n";
	return 0;
}