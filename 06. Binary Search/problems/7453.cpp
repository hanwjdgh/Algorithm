#include <iostream>
#include <ios>
#include <vector>
#include <algorithm>

using namespace std;

vector <vector <int  > > v;
vector <int > A, C;

int main() {
	cin.tie(NULL);
	cout.tie(NULL);
	ios::sync_with_stdio(false);

	int N, a, b, c, d;
	long long cnt = 0;
	cin >> N;

	v.resize(4);

	for (int i = 0; i < N; i++) {
		cin >> a >> b >> c >> d;
		v[0].push_back(a);
		v[1].push_back(b);
		v[2].push_back(c);
		v[3].push_back(d);
	}


	for (int i = 0; i < 4; i++)
		sort(v[i].begin(), v[i].end());

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			A.push_back(v[0][i] + v[1][j]);
			C.push_back(v[2][i] + v[3][j]);
		}
	}

	sort(A.begin(), A.end());
	sort(C.begin(), C.end());

	for (auto n : A) 
		cnt += ((upper_bound(C.begin(), C.end(), -n) - C.begin()) - (lower_bound(C.begin(), C.end(), -n) - C.begin()));

	cout << cnt << "\n";

	return 0;
}