#include <iostream>
#include <ios>
#include <queue>

using namespace std;

struct Node {
	int fn, sn, wt;
};

struct point {
	int num, t;
};

point recep[10]; 
point repair[10];
Node node[1001];
int N, M, K, A, B;
int visitA[11], visitB[11];
int At[11], Bt[11], Time[1001];

int main() {
	cin.tie(NULL);
	cout.tie(NULL);
	ios::sync_with_stdio(false);

	int T;

	cin >> T;

	for (int t_case = 1; t_case <= T; t_case++) {
		int ans = 0, cnt = 0, t = 0;

		queue <int > recq, repq;

		cin >> N >> M >> K >> A >> B;

		for (int i = 1; i <= N; i++)
			cin >> At[i];

		for (int i = 1; i <= M; i++)
			cin >> Bt[i];

		for (int i = 1; i <= K; i++) 
			cin >> Time[i];

		while (1) {
			for (int i = 1; i <= K; i++) 
				if (Time[i] == t)
					recq.push(i);
			
			for (int i = 1; i <= N; i++) {
				if (recep[i].num != 0 && recep[i].t == t) {
					repq.push(recep[i].num);
					recep[i].num = 0;
				}
			}
			for (int i = 1; i <= M; i++) {
				if (repair[i].num != 0 && repair[i].t == t) {
					repair[i].num = 0;
					cnt++;
				}
			}

			for (int i = 1; i <= N; i++) {
				if (recq.empty()) 
					break;
				if (recep[i].num == 0) {
					recep[i].num = recq.front();
					recep[i].t = t + At[i]; 
					recq.pop();
					node[recep[i].num].fn = i; 
				}
			}

			for (int i = 1; i <= M; i++) {
				if (repq.empty())
					break;
				if (repair[i].num == 0) {
					repair[i].num = repq.front();
					repair[i].t = t + Bt[i];
					repq.pop();
					node[repair[i].num].sn = i;
				}
			}

			if (K == cnt) {
				for (int i = 1; i <= K; i++) 
					if (node[i].fn == A && node[i].sn == B) 
						ans += i;
				break;
			}

			t++;
		}

		if (ans == 0)
			ans = -1;

		cout << "#" << t_case << " " << ans << "\n";
	}

	return 0;
}