#include <iostream>
#include <ios>
#include <algorithm>
#include <queue>

using namespace std;

struct Tree {
	int y, x, age;
};

bool operator<(Tree a, Tree b) {
	return (a.age > b.age);
}

priority_queue <Tree > pq[2];

int dir[8][2] = { {-1,-1},{-1,0},{-1,1},{0,-1},{0,1},{1,-1},{1,0},{1,1} };
int N, M, K, cur;
int soil[11][11], A[11][11];

int main() {
	cin.tie(NULL);
	cout.tie(NULL);
	ios::sync_with_stdio(false);

	int next;

	cin >> N >> M >> K;

	for (int y = 0; y < N; y++) {
		for (int x = 0; x < N; x++) {
			cin >> A[y][x];
			soil[y][x] = 5;
		}
	}

	for (int i = 0; i < M; i++) {
		Tree tree;
		cin >> tree.y >> tree.x >> tree.age;
		tree.y--, tree.x--;
		pq[cur].push(tree);
	}

	for (int i = 0; i < K; i++) {
		next = (cur + 1) % 2;
	
		queue <Tree > live, dead;

		while (!pq[cur].empty()) {
			Tree cur_tree = pq[cur].top();
			pq[cur].pop();

			if (soil[cur_tree.y][cur_tree.x] >= cur_tree.age) {
				soil[cur_tree.y][cur_tree.x] -= cur_tree.age;
				Tree next_tree;
				next_tree.y = cur_tree.y, next_tree.x = cur_tree.x, next_tree.age = cur_tree.age+1;
				live.push(next_tree);
				pq[next].push(next_tree);
			}
			else 
				dead.push(cur_tree);	
		}

		while (!dead.empty()) {
			Tree cur_tree = dead.front();
			dead.pop();
			soil[cur_tree.y][cur_tree.x] += (cur_tree.age / 2);
		}

		while (!live.empty()) {
			Tree cur_tree = live.front();
			live.pop();

			if (cur_tree.age % 5 != 0)
				continue;
			for (int j = 0; j < 8; j++) {
				int ny = cur_tree.y + dir[j][0], nx = cur_tree.x + dir[j][1];
				if (ny < 0 || nx < 0 || ny >= N || nx >= N)
					continue;
				Tree next_tree;
				next_tree.y = ny, next_tree.x = nx, next_tree.age = 1;
				pq[next].push(next_tree);
			}
		}

		for (int y = 0; y < N; y++) 
			for (int x = 0; x < N; x++) 
				soil[y][x] += A[y][x];

		cur = next;
	}

	cout << pq[next].size() << "\n";

	return 0;
}