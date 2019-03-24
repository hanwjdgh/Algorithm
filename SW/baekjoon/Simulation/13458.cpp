#include <iostream>
#include <ios>
#include <vector>

using namespace std;

vector <int > v;
int N, B, C;
long long ans;

int main() {
	cin.tie(NULL);
	cout.tie(NULL);
	ios::sync_with_stdio(false);

	int num;

	cin >> N;

	for (int i = 0; i < N; i++) {
		cin >> num;
		v.push_back(num);
	}

	cin >> B >> C;

	for (int i = 0; i < N; i++) {
		if (v[i] <= B)
			ans++;
		else {
			ans++;
			ans += (v[i] - B) / C;
			if ((v[i] - B) % C != 0)
				ans++;
		}
	}

	cout << ans << "\n";

	return 0;
}