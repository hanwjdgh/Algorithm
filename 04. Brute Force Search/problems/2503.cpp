#include <iostream>
#include <ios>
#include <tuple>
#include <vector>

using namespace std;

typedef tuple <int, int, int > t;

vector <t > v;

int main() {
	cin.tie(NULL);
	cout.tie(NULL);
	ios::sync_with_stdio(false);
	cout.precision(10);

	int N, num, x, y;
	int ans = 0;
	int fr[3], sr[3];

	cin >> N;

	for (int i = 0; i < N; i++) {
		cin >> num >> x >> y;
		v.push_back({ num,x,y });
	}

	for (int i = 123; i <= 987; i++) {
		int cnt = 0;

		fr[0] = i % 10, fr[1] = i / 10 % 10, fr[2] = i / 100;
		
		if (fr[0] == fr[1] || fr[0] == fr[2] || fr[1] == fr[2] || fr[0] == 0 || fr[1] == 0 || fr[2] == 0)
			continue;

		for (int j = 0; j < N; j++) {
			sr[0] = get<0>(v[j]) % 10, sr[1] = get<0>(v[j]) / 10 % 10, sr[2] = get<0>(v[j]) / 100;

			int st = 0, ball = 0;
			for (int k = 0; k < 3; k++) {
				if (sr[k] == fr[k])
					st++;
				if (sr[k] == fr[(k + 1) % 3] || sr[k] == fr[(k + 2) % 3])
					ball++;
			}
			if (st == get<1>(v[j]) && ball == get<2>(v[j]))
				cnt++;
		}

		if (cnt == N)
			ans++;
	}

	cout << ans << "\n";

	return 0;
}