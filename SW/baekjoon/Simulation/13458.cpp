#include <iostream>
#include <ios>

using namespace std;

int A[1000001];
int N, B, C;
long long ans;

int main() {
	cin.tie(NULL);
	cout.tie(NULL);
	ios::sync_with_stdio(false);

	int num;

	cin >> N;

	for (int i = 0; i < N; i++)
		cin >> A[i];

	cin >> B >> C;

	for (int i = 0; i < N; i++) {
		if (A[i] <= B)
			ans++;
		else {
			ans++;
			ans += (A[i] - B) / C;
			if ((A[i] - B) % C != 0)
				ans++;
		}
	}

	cout << ans << "\n";

	return 0;
}