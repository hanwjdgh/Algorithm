#include <iostream>
#include <ios>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

bool cmp(string a, string b) {
	if (a.size() == b.size()) 
		return a < b;
	return a.size() < b.size();
}

int T, N;

int main() {
	cin.tie(NULL);
	cout.tie(NULL);
	ios::sync_with_stdio(false);

	cin >> T;

	for (int t_case = 1; t_case <= T; t_case++) {
		vector <string > v;

		cin >> N;

		for (int i = 0; i < N; i++) {
			string str;
			cin >> str;
			v.push_back(str);
		}

		sort(v.begin(), v.end(), cmp);
		v.erase(unique(v.begin(), v.end()), v.end());

		cout << "#" << t_case << "\n";

		for (auto n : v)
			cout << n << "\n";
	}

	return 0;
}