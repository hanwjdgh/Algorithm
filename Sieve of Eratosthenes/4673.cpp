#include <iostream>
#include <ios>

#define MAX 10036

using namespace std;

int arr[10000];

void Kaprekar(int n) {
	int sum = n;
	if (n >= 10000) {
		sum += n / 10000;
		n %= 10000;
	}
	if (n >= 1000) {
		sum += n / 1000;
		n %= 1000;
	}
	if (n >= 100) {
		sum += n / 100;
		n %= 100;
	}
	if (n >= 10) {
		sum += n / 10;
		n %= 10;
	}
	sum += n;
	arr[sum - 1] = 1;
}

int main(void) {
	int a;
	for (a = 0; a < 10000; a++) {
		Kaprekar(a + 1);
	}
	for (a = 0; a < 10000; a++) {
		if (arr[a] != 1)
			printf("%d\n", a + 1);
	}
	return 0;
}