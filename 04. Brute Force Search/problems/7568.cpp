#include <iostream>
#include <ios>
#include <vector>

using namespace std;

typedef pair <int, int > p;

int check[51];

int main() {
	cin.tie(NULL);
	cout.tie(NULL);
	ios::sync_with_stdio(false);
	
	int N;
	int a, b;

	vector <p> v;

	cin >> N;

	for (int i = 0; i < N; i++) {
		cin >> a >> b;
		v.push_back({ a,b });
	}

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			if (i == j)
				continue;

			if (v[i].first < v[j].first && v[i].second < v[j].second)
				check[i]++;
		}
	}

	for (int i = 0; i < N; i++)
		cout << check[i] + 1 << " ";

	return 0;
}