#include <iostream>
#include <ios>
#include <bitset>
#include <string>

#define MAX 5201

using namespace std;

int matrix[MAX][MAX];
int N, ans = 1;

void compression(int x) {
	if (!(N%x)) {
		for (int i = 0; i < N; i += x)
			for (int j = 0; j < N; j += x) {

				for (int p = 0; p < x; p++)
					for (int q = 0; q < x; q++)
						if (matrix[i + p][j + q] != matrix[i][j])
							return;
			}
		ans = x;
	}
}

int main() {
	cin.tie(NULL);
	cout.tie(NULL);
	ios::sync_with_stdio(false);

	string str;

	cin >> N;

	for (int i = 0; i < N; i++) {
		cin >> str;
		for (int j = 0; j < N; j += 4) {
			int num = 0;

			if (str[j / 4] >= 'A'&&str[j / 4] <= 'F')
				num = str[j / 4] - 'A' + 10;
			else
				num = str[j / 4] - '0';

			bitset <4 > b;
			b = bitset <4 >(num);

			for (int k = 3, a = 0; k > -1; k--, a++)
				matrix[i][j + a] = b[k];
		}
	}

	for (int i = 2; i <= N / 2; i++)
		compression(i);
	compression(N);

	cout << ans << "\n";

	return 0;
}