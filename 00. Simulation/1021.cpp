#include <iostream>
#include <ios>
#include <list>
#include <algorithm>

using namespace std;

int main() {
	cin.tie(NULL);
	cout.tie(NULL);
	ios::sync_with_stdio(false);

	list<int>::iterator it;
	list <int > lst;
	int N, M, num;
	int answer = 0;

	cin >> N >> M;

	for (int i = 1; i <= N; i++)
		lst.push_back(i);

	for (int i = 0; i < M; i++) {
		cin >> num;
		if (lst.front() == num) {
			lst.pop_front();
			continue;
		}

		int L = 0, R = 0;

		for (it = lst.begin(); it != lst.end(); it++) {
			if (*it == num)
				break;
			L++;
		}
		R = lst.size() - L - 1;

		if (L <= R) {
			for (int i = 0; i < L; i++) {
				lst.push_back(lst.front());
				lst.pop_front();
				answer++;
			}
		}
		else {
			for (int i = 0; i <= R; i++) {
				lst.push_front(lst.back());
				lst.pop_back();
				answer++;
			}
		}
		lst.pop_front();
	}

	cout << answer << "\n";

	return 0;
}