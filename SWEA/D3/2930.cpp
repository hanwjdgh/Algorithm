#include <iostream>
#include <ios>
#include <queue>

using namespace std;

int T, N;

int main() {
	cin.tie(NULL);
	cout.tie(NULL);
	ios::sync_with_stdio(false);

	cin >> T;

	for (int t_case = 1; t_case <= T; t_case++) {
		priority_queue <int > pq;
		int f, s;

		cout << "#" << t_case << " ";

		cin >> N;

		for (int i = 0; i < N; i++) {
			cin >> f;

			if (f == 1) {
				cin >> s;
				pq.push(s);
			}
			else {
				if (!pq.empty()) {
					cout << pq.top() << " ";
					pq.pop();
				}
				else
					cout << "-1" << " ";
			}
		}
		cout << "\n";
	}

	return 0;
}