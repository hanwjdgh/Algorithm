#include <iostream>
#include <cstdio>

using namespace std;

int main(void){
	int N,hanum=99;
	int a;
	int x, y, z;
	scanf("%d", &N);
	if (N < 100)
		printf("%d", N);
	else{
		if (N == 1000)
			N = 999;
		for (a = 100; a <= N; a++){
			x = a / 100;
			y = (a % 100) / 10;
			z = (a % 100) % 10;
			if (x - y == y - z)
				hanum++;
		}
		printf("%d", hanum);
	}
	return 0;
}