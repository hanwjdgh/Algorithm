#include <iostream>
#include <ios>
#include <algorithm>
#include <climits>

#define MAX_V 100001

using namespace std;

struct Node {
	long long x, y;
};

bool cmp_X(const Node& A, const Node& B) {
	return A.x < B.x;
}

bool cmp_Y(const Node& A, const Node& B) {
	return A.y < B.y;
}

Node node[MAX_V];
int T, N;

long long dist(const Node& A, const Node& B) {
	return (B.x - A.x) * (B.x - A.x) + (B.y - A.y) * (B.y - A.y);
}

long long bf(int s, int e) {
	long long ret = LLONG_MAX;

	for (int i = s; i < e; i++) {
		for (int j = i + 1; j <= e; j++) {
			long long d = dist(node[i], node[j]);

			ret = min(ret, d);
		}
	}
	return ret;
}

long long closest_pair(int s, int e) {
	if (e - s + 1 <= 3)
		return bf(s, e);

	int mid = (s + e) / 2;

	long long ret = min(closest_pair(s, mid), closest_pair(mid + 1, e));

	Node midPoint = node[mid];

	Node* strip = new Node[s + e + 1];
	int idx = 0;

	for (int i = s; i <= e; i++) {
		long long tmp = midPoint.x - node[i].x;
		if (tmp * tmp < ret)
			strip[idx++] = node[i];
	}

	sort(strip, strip + idx, cmp_Y);

	for (int i = 0; i < idx - 1; i++) {
		for (int j = i + 1; j < idx; j++) {
			long long tmp = strip[j].y - strip[i].y;
			if (tmp * tmp >= ret)
				break;
			else {
				long long t_dist = dist(strip[i], strip[j]);
				ret = min(ret, t_dist);
			}
		}
	}

	delete[] strip;

	return ret;
}

int main() {
	cin.tie(NULL);
	cout.tie(NULL);
	ios::sync_with_stdio(false);

	cin >> T;

	for (int t_case = 1; t_case <= T; t_case++) {

		cin >> N;

		for (int i = 0; i < N; i++)
			cin >> node[i].x >> node[i].y;

		sort(node, node + N, cmp_X);

		cout << "#" << t_case << " " << closest_pair(0, N - 1) << "\n";

	}
	return 0;
}