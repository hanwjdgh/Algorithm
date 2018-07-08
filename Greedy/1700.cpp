#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>

using namespace std;

vector <int> v;
vector <int> plug;

int main() {
	int N,K;
	int num,cn=0;

	scanf("%d %d", &N, &K);

	for (int i = 0; i < K; i++) {
		scanf("%d", &num);
		v.push_back(num);
	}
	for (int i = 0; i < K; i++) {
		if (plug.size() < N) {
			if (find(plug.begin(), plug.end(), v[i]) != plug.end())
				continue;
			else
				plug.push_back(v[i]);
		}
		else {
			if (find(plug.begin(), plug.end(), v[i]) != plug.end())
				continue;
			else {
				int ridx,pre=-1;
				for (int a = 0; a < N; a++) {
					int idx,cnt=0;
					for (int b = i; b < K; b++) {
						if (v[b] == plug[a]) {
							idx = b;
							cnt++;
							break;
						}
					}
					if (cnt == 0) {
						ridx = a;
						break;
					}
					else {
						if (pre < idx) {
							ridx = a;
							pre = idx;
						}
					}
				}
				plug[ridx] = v[i];
				cn++;
			}
		}
	}
	printf("%d\n", cn);
	return 0;
}