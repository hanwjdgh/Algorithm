#include <iostream>
#include <ios>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

int alcnt[26];

int main() {
	cin.tie(NULL);
	cout.tie(NULL);
	ios::sync_with_stdio(false);

	vector <int > v;
	int n, k, num;
	long long ans = 0;
	string str;

	cin >> n >> k;

	for (int i = 0; i < n; i++) {
		cin >> num;
		v.push_back(num);
	}

	cin >> str;

	int chk = 0;
	for (int i = 0; i < n; i = chk) {
		chk = i;
		while (str[i] == str[chk])
			chk++;
		vector<int>::iterator s = v.begin();
		vector<int>::iterator e = v.begin();
		advance(s, i);
		advance(e, chk);

		sort(s, e);

		int cnt = 0;
		for (int j = chk - 1; j >= i; j--) {
			ans += v[j];
			cnt++;
			if (cnt == k)
				break;
		}
	}

	cout << ans << "\n";

	return 0;
}