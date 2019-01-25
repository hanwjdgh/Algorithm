#include <iostream>
#include <ios>
#include <queue>
#include <vector>

#define MAX 10000

using namespace std;
typedef pair <int, char > p;

int main() {
	cin.tie(NULL);
	ios::sync_with_stdio(false);

	int T;

	cin >> T;
	while (T--) {
		int visit[MAX] = { 0, };
		int prev[MAX] = { 0, };
		char state[MAX];
		queue <p > q;

		int A, B;

		cin >> A >> B;
		fill(state, state + MAX, '0');
		state[A] = '0';
		q.push({ A,'0' });
		visit[A] = 1;

		while (!q.empty()) {
			int cur = q.front().first;
			q.pop();

			if (cur == B) 
				break;
			
			for (int i = 0; i < 4; i++) {
				int ncur;
				char ns;
				if (i == 0) {
					ncur = (cur * 2) % MAX;
					ns = 'D';
				}
				else if (i == 1) {
					ncur = (cur + 9999) % MAX;
					ns = 'S';
				}
				else if (i == 2) {
					ncur = (cur != 0) ? ((cur % 1000) * 10) + (cur / 1000) : 0;
					ns = 'L';
				}
				else {
					ncur = (cur != 0) ? (cur / 10) + ((cur % 10) * 1000) : 0;
					ns = 'R';
				}
				if (!visit[ncur]) {
					visit[ncur] = 1;
					prev[ncur] = cur;
					state[ncur] = ns;
					q.push({ ncur,ns });
				}
			}
		}

		vector <char > v;
		for (int i = B; i != A; i = prev[i]) 
			v.push_back(state[i]);
		
		int len = v.size()-1;
		for (int i = len; i > -1; i--)
			cout << v[i];
		cout << endl;
	}
	return 0;
}