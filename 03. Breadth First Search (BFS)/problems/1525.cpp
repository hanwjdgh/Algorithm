#include <iostream>
#include <ios>
#include <queue>
#include <map>
#include <string>

using namespace std;

int dx[4] = { 0,1,0,-1 }, dy[4] = { 1,0,-1,0 };
queue<int> q;
map<int, int> m;

int main() {
	int num = 0;

	for (int i = 0; i < 9; i++) {
		int temp;
		cin >> temp;
		if (temp == 0)
			temp = 9;
		num = temp + num * 10;
	}

	q.push(num);
	m[num] = 0;

	while (!q.empty()) {
		int x = q.front();
		q.pop();

		string number = to_string(x);
		int pos = number.find('9');
		int row = pos / 3;
		int col = pos % 3;

		for (int i = 0; i < 4; i++) {
			int nr = row + dy[i];
			int nc = col + dx[i];
			if (nr < 0 || nc < 0 || nr >= 3 || nc >= 3)
				continue;

			string temp = number;
			swap(temp[pos], temp[3 * nr + nc]);
			int next = stoi(temp);

			if (m.count(next) == 0){
				q.push(next);
				m[next] = m[x] + 1;
			}

		}
	}

	if (m.count(123456789) == 0)
		cout << -1 << '\n';
	else
		cout << m[123456789] << '\n';
}