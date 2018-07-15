#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>

using namespace std;

vector <long long > v;

long long find(int s, int f) {
	if (s == f)
		return v[s]*v[s];

	int mid = (s + f) / 2;
	long long ret = max(find(s,mid),find(mid+1,f));
	int L = mid, R = mid; 
	long long min_v = v[mid],hap = v[mid];

	while (1) {
		ret = max(ret, min_v*hap);
		if (L == s && R == f)
			break;
		long long Lv = L > s ? v[L-1] : -1;
		long long Rv = R < f ? v[R + 1] : -1;

		if (L == s || Rv > Lv) {
			R++;
			min_v = min(min_v, Rv);
			hap += Rv;
		}
		else if (R == f || Lv >= Rv) {
			L--;
			min_v = min(min_v, Lv);
			hap += Lv;
		}
	}
	return ret;
}

int main() {
	int N, num;

	cin >> N;
	for (int i = 0; i < N; i++) {
		cin >> num;
		v.push_back(num);
	}

	printf("%lld",find(0, N - 1));
	return 0;
}