#include <iostream>
#include <ios>
#include <algorithm>
#include <stack>

#define MAX_V 100001

using namespace std;

typedef long long ll;

struct Node {
	int x, y, p, q;
};

bool cmp(const Node& A, const Node& B) {
	if (1LL * A.q * B.p != 1LL * A.p * B.q)
		return 1LL * A.q * B.p < 1LL * A.p * B.q;
	if (A.y != B.y)
		return A.y < B.y;
	return A.x > B.x;
}

ll ccw(const Node& A, const Node& B, const Node& C) {
	return 1LL * (B.x - A.x) * (C.y - A.y) - 1LL * (B.y - A.y) * (C.x - A.x);
}

Node node[MAX_V];
int T, N;

int main() {
	cin.tie(NULL);
	cout.tie(NULL);
	ios::sync_with_stdio(false);

	cin >> T;

	for (int t_case = 1; t_case <= T; t_case++) {

		cin >> N;

		for (int i = 0; i < N; i++) {
			cin >> node[i].x >> node[i].y;

			node[i].p = 0, node[i].q = 0;
		}
		sort(node, node + N, cmp);

		for (int i = 1; i < N; i++) {
			node[i].p = node[i].x - node[0].x;
			node[i].q = node[i].y - node[0].y;
		}

		sort(node + 1, node + N, cmp);

		stack <int > s;

		s.push(0);
		s.push(1);

		int next = 2;

		while (next < N) {
			while (s.size() >= 2) {
				int first, second;
				second = s.top();
				s.pop();
				first = s.top();

				if (ccw(node[first], node[second], node[next]) > 0) {
					s.push(second);
					break;
				}
			}
			s.push(next++);
		}

		cout << "#" << t_case << " " << s.size() << "\n";


	}
	return 0;
}