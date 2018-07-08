#include <iostream>
#include <cstdio>
#include <algorithm>

using namespace std;

int main() {
	int l, w, h, n;
	int a[22],x,y;
	long long cnt=0, ans=0, tmp=0;

	scanf("%d %d %d", &l, &w, &h);
	scanf("%d", &n);

	for (int i = 0; i < n; i++) {
		scanf("%d %d", &x, &y);
		a[x] = y;
	}

	for (int i = n-1; i >= 0; i--) {
		cnt <<= 3;
		tmp = min((long long)a[i], (long long)(l >> i)*(w >> i)*(h >> i) - cnt);
		cnt += tmp;
		ans += tmp;
	}

	printf("%lld", cnt == (long long)l * w * h ? ans : -1);

	return 0;
}