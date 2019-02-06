#include <iostream>
#include <ios>
#include <queue>
#include <algorithm>

using namespace std;

typedef pair <int, int > p;

int main() {
	cin.tie(NULL);
	cout.tie(NULL);
	ios::sync_with_stdio(false);

	int test, N, M;

	cin >> test;

	for (int i = 0; i < test; i++) {
		queue <p > q;
		int num, max_v = 0, cnt = 0;

		cin >> N >> M;

		for (int i = 0; i < N; i++) {
			cin >> num;
			q.push({ i,num });
			max_v = max(max_v, num);
		}

		while (!q.empty()) {
			p temp = q.front();
			q.pop();

			if (temp.second == max_v) {
				cnt++;
				if (temp.first == M) {
					cout << cnt << "\n";
					break;
				}
				else {
					max_v = 0;
					for (int i = 0; i < q.size(); i++) {
						p tmp = q.front();
						max_v = max(max_v, tmp.second);
						q.pop();
						q.push(tmp);
					}
				}
			}
			else
				q.push(temp);
		}
	}
	return 0;
}