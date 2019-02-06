#include <iostream>
#include <ios>
#include <vector>

using namespace std;

vector <double > v;
int dir[4][2] = { {0,1},{0,-1},{-1,0},{1,0} };
int visit[31][31];
int N;

double dfs(int x, int y, int cnt) {
	if (cnt == N)
		return 1.0;

	double ret = 0.0;
	visit[x][y] = 1;

	for (int i = 0; i < 4; i++) {
		int nx = x + dir[i][0], ny = y + dir[i][1];
		if (!visit[nx][ny])
			ret += v[i] * dfs(nx, ny, cnt + 1);
	}

	visit[x][y] = 0;
	return ret;
}


int main() {
	cin.tie(NULL);
	cout.tie(NULL);
	ios::sync_with_stdio(false);
	cout.setf(ios::fixed);

	double num;

	cin >> N;

	for (int i = 0; i < 4; i++) {
		cin >> num;
		v.push_back(num / 100);
	}

	cout.precision(10);
	cout << dfs(15, 15, 0) << endl;

	return 0;
}