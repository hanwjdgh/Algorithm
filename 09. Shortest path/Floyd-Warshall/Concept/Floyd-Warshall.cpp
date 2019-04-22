#include <iostream>
#include <ios>
#include <stack>

#define INF 99999 
#define NIL -1

using namespace std;

int dist[4][4] = {
	{ 0,   5,  INF, 10 },
    { INF, 0,   3, INF },
    { INF, INF, 0,   1 },
    { INF, INF, INF, 0 }
};
int pre[4][4] = {
	{ NIL, 0, NIL, 0},
	{ NIL, NIL, 1, NIL },
	{ NIL, NIL, NIL, 2 },
	{ NIL, NIL, NIL, NIL }
};
stack <int > s;

int main() {
	cin.tie(NULL);
	cout.tie(NULL);
	ios::sync_with_stdio(false);

	for (int k = 0; k < 4; k++) {
		for (int i = 0; i < 4; i++) {
			for (int j = 0; j < 4; j++) {
				if (dist[i][k] + dist[k][j] < dist[i][j]) {
					dist[i][j] = dist[i][k] + dist[k][j];
					pre[i][j] = pre[k][j];
				}
			}
		}
	}

	for (int i = 0; i < 4; i++) {
		for (int j = 0; j < 4; j++) {
			if (dist[i][j] == INF)
				cout << "INF" << " ";
			else
				cout << dist[i][j] << " ";
		}
		cout << "\n";
	}
	cout << "\n";

	for (int i = 0; i < 4; i++) {
		for (int j = 0; j < 4; j++) {
			if (pre[i][j] == NIL)
				cout << "NIL" << " ";
			else
				cout << pre[i][j] << " ";
		}
		cout << "\n";
	}
	cout << "\n";

	for (int i = 0; i < 4; i++) {
		for (int j = 0; j < 4; j++) {
			if (pre[i][j] == NIL)
				continue;
			cout << i << " -> " << j << " : ";
			
			int p = j;
			s.push(j);

			while (i != pre[i][p]) {
				p = pre[i][p];
				s.push(p);
			}

			cout << i;
			while (!s.empty()) {
				cout << " - " << s.top();
				s.pop();
			}
			cout << "\n";
		}
	}

	return 0;
}