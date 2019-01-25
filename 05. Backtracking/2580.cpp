#include <iostream>
#include <ios>
#include <vector>

using namespace std;

typedef pair <int, int > p;
vector <p > v;
int sudoku[9][9];
int cnt = 0, zero_s, chk = 0;

void backtrack() {
	if (chk == 1)
		return;
	if (cnt == zero_s) {
		if (chk == 0) {
			for (int i = 0; i < 9; i++) {
				for (int j = 0; j < 9; j++)
					cout << sudoku[i][j] << " ";
				cout << endl;
			}
		}
		chk = 1;
		return;
	}

	bool no;
	int x = v[cnt].first, y = v[cnt].second;
	int sqx = (x / 3) * 3, sqy = (y / 3) * 3;

	for (int i = 1; i <= 9; i++) {
		no = false;
		for (int j = 0; j < 9; j++) {
			if (sudoku[x][j] == i || sudoku[j][y] == i) {
				no = true;
				break;
			}
		}

		for (int j = sqx; j < sqx + 3; j++) {
			for (int k = sqy; k < sqy + 3; k++) {
				if (sudoku[j][k] == i) {
					no = true;
					break;
				}
			}
		}
		if (!no) {
			sudoku[x][y] = i;
			cnt++;
			backtrack();
			cnt--;
			sudoku[x][y] = 0;
		}
	}
}

int main() {
	cin.tie(NULL);
	ios::sync_with_stdio(false);

	for (int i = 0; i < 9; i++) {
		for (int j = 0; j < 9; j++) {
			cin >> sudoku[i][j];
			if (sudoku[i][j] == 0)
				v.push_back({ i,j });
		}
	}
	zero_s = v.size();
	backtrack();
	return 0;
}