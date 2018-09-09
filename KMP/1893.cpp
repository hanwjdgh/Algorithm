#include <iostream>
#include <ios>
#include <string>
#include <map>
#include <vector>

#define MAX 50001

using namespace std;

int fail[MAX];

int main() {
	cin.tie(NULL);
	cout.tie(NULL);
	ios::sync_with_stdio(false);

	int T;

	cin >> T;

	while (T--) {
		map <char, int> m;
		vector <string> v;
		vector <int > ans;
		string A, W, S;

		cin >> A >> W >> S;

		int a_len = A.length();
		int w_len = W.length();
		int s_len = S.length();

		for (int i = 0; i < a_len; i++)
			m[A[i]] = i;

		for (int i = 0; i < a_len; i++) {
			string temp = W;
			for (int j = 0; j < w_len; j++)
				temp[j] = A[(m[temp[j]] + i) % a_len];
			v.push_back(temp);
		}


		int v_size = v.size();
		for (int i = 0; i < v_size; i++) {
			fill(fail, fail + MAX, 0);

			string temp = v[i];
			for (int a = 1, b = 0; a < w_len; a++) {
				while (b > 0 && temp[a] != temp[b])
					b = fail[b - 1];
				if (temp[a] == temp[b])
					fail[a] = ++b;
			}

			int cnt = 0;
			for (int a = 0, b = 0; a < s_len; a++) {
				while (b > 0 && S[a] != temp[b])
					b = fail[b - 1];
				if (S[a] == temp[b]) {
					if (b == w_len - 1) {
						cnt++;
						b = fail[b];
					}
					else
						b++;
				}
			}
			if (cnt == 1)
				ans.push_back(i);
		}

		int a_size = ans.size();
		if (a_size == 0)
			cout << "no solution" << "\n";
		else if (a_size == 1)
			cout << "unique: " << ans[0] << "\n";
		else {
			cout << "ambiguous: ";
			for (auto j : ans)
				cout << j << " ";
			cout << "\n";
		}
	}
	return 0;
}