#include <iostream>
#include <cstdio>
#include <cmath>

using namespace std;

int arr[10] = { 0, };

void cal(int n) {
	while (n > 0) {
		++arr[n % 10];
		n /= 10;
	}
}

int main(void) {
	int num, a, tnum, cnt = 0, ts;
	scanf("%d", &num);

	if (num < 20) {
		for (a = 1; a <= num; a++)
			cal(a);
	}
	else {
		tnum = 1;
		while (num > 10) {
			while (tnum % 10 != 0) {
				arr[tnum] += pow(10, cnt);
				++tnum;

			}
			while (num % 10 != 9) {
				ts = num;
				while (ts > 0) {
					arr[ts % 10] += pow(10, cnt);
					ts /= 10;
				}
				--num;
			}

			for (a = 0; a < 10; a++) {
				arr[a] += (((num / 10) - (tnum / 10) + 1)*pow(10, cnt));
			}

			tnum /= 10;
			num /= 10;
			++cnt;
			if (num < 10) {
				for (a = tnum; a <= num; a++) {
					arr[a] += pow(10, cnt);
				}
			}
			if (num > 9 && num < 20) {
				while (num != 0) {
					ts = num;
					while (ts > 0) {
						arr[ts % 10] += pow(10, cnt);
						ts /= 10;
					}
					--num;
				}
			}
		}
	}
	for (a = 0; a < 10; a++)
		printf("%d ", arr[a]);

	return 0;
}