#include <iostream>
#include <ios>
#include <vector>

using namespace std;

vector <int > numbers(1000001, 1);
int T, D, A, B, ans;

int main() {
	cin.tie(NULL);
	cout.tie(NULL);
	ios::sync_with_stdio(false);

	numbers[0] = numbers[1] = 0;
	for (int i = 2; i <= 1000000; i++) {
		if (numbers[i] == 1) {
			for (int j = 2; j*i <= 1000000; j++) {
				numbers[j*i] = 0;
			}
		}
	}
	
	
	cin >> T;

	for (int t_case = 1; t_case <= T; t_case++) {
		ans = 0;

		cin >> D >> A >> B;

		for (int i = A; i <= B; i++) {
			if (!numbers[i])
				continue;

			int temp = i;
			
			while (temp > 0) {
				if (temp % 10 == D) {
					ans++;
					break;
				}
				temp /= 10;
			}
		}

		cout << "#" << t_case << " " << ans << "\n";
	}

	return 0;
}