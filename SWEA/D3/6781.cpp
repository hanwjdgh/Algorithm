#include <iostream>
#include <ios>
#include <string>
#include <algorithm>

using namespace std;

int arr[3][10];
int T;

int f_check() {
	int fcnt = 0;
	
	for (int i = 0; i < 3; i++) {
		for (int j = 1; j < 10; ) {
			if (arr[i][j] >= 3) {
				arr[i][j] -= 3;
				fcnt++;
				continue;
			}
			j++;
		}

		for (int j = 1; j < 8; ) {
			if (arr[i][j] >= 1 && arr[i][j + 1] >= 1 && arr[i][j + 2] >= 1) {
				arr[i][j]--;
				arr[i][j+1]--;
				arr[i][j+2]--;
				fcnt++;
				continue;
			}
			j++;
		}
	}

	return fcnt;
}

int s_check() {
	int scnt = 0;

	for (int i = 0; i < 3; i++) {
		for (int j = 1; j < 8; ) {
			if (arr[i][j] >= 1 && arr[i][j + 1] >= 1 && arr[i][j + 2] >= 1) {
				arr[i][j]--;
				arr[i][j + 1]--;
				arr[i][j + 2]--;
				scnt++;
				continue;
			}
			j++;
		}

		for (int j = 1; j < 10; ) {
			if (arr[i][j] >= 3) {
				arr[i][j] -= 3;
				scnt++;
				continue;
			}
			j++;
		}
	}

	return scnt;
}

int main() {
	cin.tie(NULL);
	cout.tie(NULL);
	ios::sync_with_stdio(false);

	cin >> T;

	for (int t_case = 1; t_case <= T; t_case++) {
		bool err = false;
		int max_v = 0;
		string card, color;

		cin >> card >> color;

		for (int i = 0; i < 10; i++) {
			if (color[i] == 'R') 
				arr[0][card[i] - '0']++;
			else if (color[i] == 'G') 
				arr[1][card[i] - '0']++;
			else 
				arr[2][card[i] - '0']++;
		}
		
		cout << "#" << t_case << " ";

		max_v = max(f_check(), s_check());

		if (max_v < 3)
			err = true;

		if (!err)
			cout << "Win" << "\n";
		else
			cout << "Continue" << "\n";

		for (int i = 0; i < 3; i++)
			for (int j = 0; j < 10; j++)
				arr[i][j] = 0;
	}

	return 0;
}