#include <iostream>
#include <ios>
#include <vector>
#include <algorithm>

using namespace std;

vector <vector <int > > v;
int trot[4];

void find(int cur, int rot) {
	fill(trot, trot + 4, 0);
	trot[cur] = rot;

	for (int i = cur; i > 0; i--) {
		if (v[i][6] != v[i - 1][2])
			trot[i - 1] = -trot[i];
		else
			trot[i - 1] = 0;
	}

	for (int i = cur; i < 3; i++) {
		if (v[i][2] != v[i + 1][6])
			trot[i + 1] = -trot[i];
		else
			trot[i + 1] = 0;
	}

	for (int i = 0; i < 4; i++) {
		if (trot[i] == 0)
			continue;
		else if (trot[i] == 1) 
			rotate(v[i].rbegin(), v[i].rbegin() + 1, v[i].rend());
		else
			rotate(v[i].begin(), v[i].begin() + 1, v[i].end());
	}
}

int main() {
	cin.tie(NULL);
	cout.tie(NULL);
	ios::sync_with_stdio(false);

	int T;

	cin >> T;

	for (int t_case = 1; t_case <= T; t_case++) {
		int K, a, b, num, ans = 0;
		v.clear();
		v.resize(4);
		
		cin >> K;

		for (int i = 0; i < 4; i++) {
			for (int j = 0; j < 8; j++) {
				cin >> num;
				v[i].push_back(num);
			}
		}

		for (int i = 0; i < K; i++) {
			cin >> a >> b;
			find(a - 1, b);
		}

		for (int i = 0; i < 4; i++) 
			ans += v[i][0] * pow(2, i*v[i][0]);
		
		cout << "#" << t_case << " " << ans<< "\n";
	}

	return 0;

}