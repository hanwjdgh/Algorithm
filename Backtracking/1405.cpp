#include <iostream>
#include <ios>

using namespace std;
int dx[4] = { 0,0,1,-1 }, dy[4] = { 1,-1,0,0 };
double per[4];
int N, visit[30][30] = { 0, };
int cnt;

double backtrack(int x, int y) {
	if (cnt == N) 
		return 1.0;

	double ret = 0.0;
	visit[x][y] = 1;

	for (int i = 0; i < 4; i++) {
		int nx = x + dx[i], ny = y + dy[i];
		if (!visit[nx][ny]) {
			cnt++;
			ret += per[i] * backtrack(nx, ny);
			cnt--;
		}
	}
	visit[x][y] = 0;
	return ret;
}

int main() {
	cin.tie(NULL);
	ios::sync_with_stdio(false);
	cout.setf(ios::fixed);

	cin >> N;
	for (int i = 0; i < 4; i++) {
		cin >> per[i];
		per[i] /= 100;
	}
	cout.precision(10);
	cout << backtrack(15, 15) << endl;

	return 0;
}