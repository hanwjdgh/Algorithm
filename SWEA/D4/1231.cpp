#include <iostream>
#include <ios>
#include <vector>

using namespace std;

char tree[101];
int N;

void inorder(int cur) {
	if (tree[cur] == '0' || cur > N)
		return;

	inorder(cur * 2);
	cout << tree[cur];
	inorder(cur * 2 + 1);
}

int main() {
	cin.tie(NULL);
	cout.tie(NULL);
	ios::sync_with_stdio(false);


	for (int t = 1; t <= 10; t++) {
		cin >> N;

		fill(tree, tree + N + 1, '0');
		for (int i = 1; i <= N; i++) {
			int a, b, c;
			char ch;

			cin >> a >> tree[i];

			if ((N % 2 == 0 && (i < N / 2)) || (N % 2 == 1 && i <= (N - 1) / 2))
				cin >> b >> c;
			else if (N % 2 == 0 && i == N / 2)
				cin >> b;
		}

		cout << "#" << t << " ";
		inorder(1);
		cout << "\n";
	}

	return 0;
}