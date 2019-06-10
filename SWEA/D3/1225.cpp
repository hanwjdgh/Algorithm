#include <iostream>
#include <ios>
#include <queue>
#include <vector>

using namespace std;

int main() {
	cin.tie(NULL);
	cout.tie(NULL);
	ios::sync_with_stdio(false);

	for (int t = 1; t <= 10; t++) {
		queue <int > q;

		int n, num;

		cin >> n;

		cout << "#" << t << " ";

		for (int i = 0; i < 8; i++) {
			cin >> num;
			q.push(num);
		}

		while (1) {
			int chk = 0;
			for (int i = 1; i <= 5; i++) {
				int temp = q.front() - i;

				if (temp <= 0) {
					temp = 0;
					chk = 1;
				}

				q.pop();
				q.push(temp);

				if (chk)
					break;
			}
			if (chk)
				break;
		}

		while (!q.empty()) {
			cout << q.front() << " ";
			q.pop();
		}
		cout << "\n";
	}

	return 0;
}