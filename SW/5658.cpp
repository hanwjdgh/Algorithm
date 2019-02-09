#include <iostream>
#include <ios>
#include <string>
#include <vector>
#include <algorithm>
#include <functional>

using namespace std;

vector <int > v;

void convert(string str, int t) {
	for (int i = 0; i < str.length(); i += t) {
		int sup = t - 1, temp = 0;
		for (int j = i; j < i + t; j++) {
			if (str[j] >= '0' && str[j] <= '9')
				temp += pow(16, sup) * (str[j] - '0');
			else
				temp += pow(16, sup) * (str[j] - 'A' + 10);
			sup--;
		}
		v.push_back(temp);
	}
}

int main() {
	cin.tie(NULL);
	cout.tie(NULL);
	ios::sync_with_stdio(false);

	int T;

	cin >> T;

	for (int t = 1; t <= T; t++) {
		int N, K, rot;
		string str, tmp;

		v.clear();

		cin >> N >> K >> str;

		rot = (N / 4);
		for (int i = 0; i < rot; i++) {
			convert(str, rot);
			tmp = str[N - 1] + str.substr(0, N - 1);
			str = tmp;
		}

		sort(v.begin(), v.end(), greater<int >());

		int cnt = 0, tnum = 0;
		for (auto n : v) {
			if (tnum == n)
				continue;
			tnum = n;
			cnt++;
			if (cnt == K)
				break;

		}
		cout << "#" << t << " " << tnum << "\n";
	}

	return 0;
}