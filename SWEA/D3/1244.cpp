#include <iostream>
#include <ios>
#include <vector>
#include <string>
#include <algorithm>
#include <cmath>

#define MAX 1000001

using namespace std;

vector <int > v;
int visit[MAX];
int n, max_v;

void search(int cnt) {
	int val = 0;

	for (int i = 0; i < v.size(); i++)
		val += v[i] * pow(10, v.size() - 1 - i);

	if (cnt == n) {
		max_v = max(max_v, val);
		return;
	}

	if (visit[val])
		return;

	visit[val] = 1;

	for (int i = 0; i < v.size(); i++) {
		for (int j = 0; j < v.size(); j++) {
			if (i == j)
				continue;
			swap(v[i], v[j]);
			search(cnt + 1);
			swap(v[i], v[j]);
		}
	}
}

int main() {
	cin.tie(NULL);
	cout.tie(NULL);
	ios::sync_with_stdio(false);

	int T;

	cin >> T;

	for (int t = 1; t <= T; t++) {
		string str;
		fill(visit, visit + MAX, 0);
		v.clear();
		max_v = 0;

		cin >> str >> n;

		for (int i = 0; i < str.length(); i++)
			v.push_back(str[i] - '0');

		search(0);

		cout << "#" << t << " " << max_v << "\n";
	}
	return 0;
}