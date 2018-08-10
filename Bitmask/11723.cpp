#include <iostream>
#include <cstdio>
#include <cstring>

using namespace std;

int main() {
	char str[12];
	int M, x, n = 0;

	scanf("%d", &M);
	while (M--) {
		scanf("%s", &str);
		scanf("%d", &x);
		if (!strcmp(str, "add")) 
			n |= (1 << x);
		else if (!strcmp(str, "remove"))
			n &= ~(1 << x);
		else if (!strcmp(str, "check"))
			printf("%d\n", (n&(1 << x)) == 0 ? 0 : 1);
		else if (!strcmp(str, "toggle"))
			n ^= (1 << x);
		else if (!strcmp(str, "all"))
			n = (1 << 21) - 1;
		else 
			n = 0;
	}
	return 0;
}