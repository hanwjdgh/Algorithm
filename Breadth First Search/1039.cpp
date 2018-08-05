#include <iostream>
#include <ios>
#include <queue>
#include <string>
#include <map>

using namespace std;
queue <string > q;

int main() {
	cin.tie(NULL);
	ios::sync_with_stdio(false);

	string str;
	int k, max_v = 0, len;

	cin >> str >> k;

	len = str.length();
	q.push(str);

	for (int i = 0; i < k; i++) {
		int sq = q.size();
		map <string, int > m;

		for (int j = 0; j < sq; j++) {
			string cur = q.front();
			q.pop();
			if (m.count(cur) != 0)
				continue;
			m[cur] = 1;
			for (int a = 0; a < len - 1; a++) {
				for (int b = a + 1; b < len; b++) {
					if (a>0 || str[b] != '0') {
						swap(cur[a], cur[b]);
						q.push(cur);
						swap(cur[a], cur[b]);
					}

				}
			}
		}
	}

	while (!q.empty()) {
		max_v = max(max_v, stoi(q.front()));
		q.pop();
	}
	if (max_v == 0)
		cout << "-1" << endl;
	else
		cout << max_v << endl;
	return 0;
}