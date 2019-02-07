#include <iostream>
#include <ios>
#include <vector>
#include <string>
#include <cctype>
#include <algorithm>

using namespace std;

typedef pair <string, int > p;

int main() {
	cin.tie(NULL);
	cout.tie(NULL);
	ios::sync_with_stdio(false);

	vector <string > v;
	vector <p > vp;
	int N, M;
	string str;

	cin >> N >> M;

	for (int i = 0; i < N; i++) {
		cin >> str;
		v.push_back(str);
		vp.push_back({str,i + 1});
	}

	sort(vp.begin(), vp.end());

	for (int i = 0; i < M; i++) {
		cin >> str;
		if (isdigit(str[0]))
			cout << v[stoi(str)-1] << "\n";
		else {
			int L = 0, R = N;

			while (L <= R) {
				int mid = (L + R) / 2;

				if (vp[mid].first == str) {
					cout << vp[mid].second << "\n";
					break;
				}

				if (vp[mid].first > str)
					R = mid - 1;
				else
					L = mid + 1;
			}
		}
	}

	return 0;
}