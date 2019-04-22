#include <iostream>
#include <ios>
#include <vector>
#include <queue>
#include <stack>
#include <memory.h>

using namespace std;

struct Node {
	int dst, weight;
};

bool operator<(Node a, Node b) {
	return (a.weight > b.weight);
}

priority_queue <Node > pq;
vector <Node > ad[5];
stack <int > s;
int dist[5], pre[5];

int main() {
	cin.tie(NULL);
	cout.tie(NULL);
	ios::sync_with_stdio(false);

	ad[0].push_back({ 1,2 });
	ad[0].push_back({ 3,6 });
	ad[1].push_back({ 2,3 });
	ad[1].push_back({ 3,8 });
	ad[1].push_back({ 4,5 });
	ad[2].push_back({ 4,7 });
	ad[3].push_back({ 4,9 });

	memset(dist, -1, sizeof(dist));
	memset(pre, -1, sizeof(pre));

	pq.push({ 0,0 });

	while (!pq.empty()) {
		Node cur = pq.top();
		pq.pop();

		if (dist[cur.dst] != -1)
			continue;

		dist[cur.dst] = cur.weight;

		for (auto n : ad[cur.dst]) {
			if (dist[n.dst] != -1)
				continue;

			pre[n.dst] = cur.dst;
			pq.push({ n.dst, n.weight + cur.weight });
		}
	}

	for (int i = 0; i < 5; i++) {
		if (dist[i] == -1)
			cout << "INF" << " ";
		else
			cout << dist[i] << " ";
	}
	cout << "\n";

	for (int i = 0; i < 5; i++)
		cout << pre[i] << " ";
	cout << "\n";

	for (int i = 0; i < 5; i++) {
		cout << "To " << i << " : ";

		if (dist[i] == -1)
			continue;

		int next = pre[i];
		while (next != -1) {
			s.push(next);
			next = pre[next];
		}

		while (!s.empty()) {
			cout << s.top() << " - ";
			s.pop();
		}
		cout << i << "\n";
	}

	return 0;
}