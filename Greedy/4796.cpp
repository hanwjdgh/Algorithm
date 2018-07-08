#include <iostream>
#include <cstdio>

using namespace std;

int main() {
	int L, P, V;
	int val,cnt=1;
	while (1) {
		scanf("%d %d %d", &L, &P, &V);
		if (!L && !P && !V)
			break;

		if((V%P)<L)
			printf("Case %d: %d\n",cnt++, (V / P)*L + (V%P));
		else
			printf("Case %d: %d\n", cnt++, (V / P)*L + L);
	}
	return 0;
}