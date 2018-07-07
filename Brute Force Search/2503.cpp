#include <iostream>
#include <cstdio>
#include <vector>

using namespace std;

vector<int> num;
vector<pair<int, int> > p;

int main() {
	int N,ans=0;
	int n, a, b;
	int ar[3], br[3];
	scanf("%d",&N);
	for (int i = 0; i < N; i++) {
		scanf("%d %d %d", &n, &a, &b);
		num.push_back(n);
		p.push_back(make_pair(a, b));
	}
	
	for (int i = 123; i <= 987; i++) {
		int cnt = 0;
		ar[0] = i % 10, ar[1] = i / 10 % 10, ar[2] = i / 100;
		if (ar[0] == ar[1] || ar[1] == ar[2] || ar[2] == ar[0]||ar[1]==0||ar[0]==0)
			continue;
		for (int j = 0; j < N; j++) {
			br[0] = num[j] % 10, br[1] = num[j] / 10 % 10, br[2] = num[j] / 100;
			int st=0, ball=0;
			for (int k = 0; k < 3; k++) {
				if (br[k] == ar[k])
					st++;
				if (br[k] == ar[(k+1)%3] || br[k] == ar[(k + 2) % 3])
					ball++;
			}
			if (st == p[j].first && ball == p[j].second)
				cnt++;
		}
		if (cnt == N)
			ans++;
	}
	printf("%d\n", ans);
	return 0;
}