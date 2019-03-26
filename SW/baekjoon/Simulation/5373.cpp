#include <iostream>
#include <ios>

using namespace std;

int T, n;
char side, dir;
char indx[6] = { 'U','F','D','B','L','R' };

int cw[12] = { 6,3,0,7,4,1,8,5,2 };
int ccw[12] = { 2,5,8,1,4,7,0,3,6 };
int rot[6][12] = {
	{ 33,34,35,47,46,45,11,10,9,38,37,36 },
	{ 6,7,8,45,48,51,20,19,18,44,41,38 },
	{ 15,16,17,51,52,53,29,28,27,42,43,44 },
	{ 2,1,0,36,39,42,24,25,26,53,50,47 },
	{ 0,3,6,9,12,15,18,21,24,27,30,33 },
	{ 8,5,2,35,32,29,26,23,20,17,14,11 }
};

int main() {
	cin.tie(NULL);
	cout.tie(NULL);
	ios::sync_with_stdio(false);

	cin >> T;

	while (T--) {
		char cube[54];
		char init[7] = "wryogb";

		for (int i = 0; i < 6; i++)
			for (int j = 0; j < 9; j++)
				cube[i * 9 + j] = init[i];

		cin >> n;

		while (n--) {
			cin >> side >> dir;

			int id;
			char sub_cube[12] = { '0', };
			for (int i = 0; i < 6; i++) {
				if (indx[i] == side) {
					id = i;
					break;
				}
			}

			char temp[12];
			if (dir == '+') {
				for (int i = 0; i < 12; i++)
					temp[i] = cube[rot[id][(i + 9) % 12]];
				for (int i = 0; i < 12; i++)
					cube[rot[id][i]] = temp[i];
				for (int i = 0; i < 9; i++)
					sub_cube[i] = cube[9 * id + cw[i]];
			}
			else {
				for (int i = 0; i < 12; i++)
					temp[i] = cube[rot[id][(17 - i) % 12]];
				for (int i = 0; i < 12; i++)
					cube[rot[id][(26 - i) % 12]] = temp[i];
				for (int i = 0; i < 9; i++)
					sub_cube[i] = cube[9 * id + ccw[i]];
			}

			for (int i = 0; i < 9; i++)
				cube[id * 9 + i] = sub_cube[i];
		}
		for (int i = 0; i < 3; i++) {
			for (int j = 0; j < 3; j++)
				cout << cube[i * 3 + j];
			cout << endl;
		}
	}

	return 0;
}