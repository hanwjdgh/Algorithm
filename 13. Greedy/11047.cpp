#include <iostream>
#include <cstdio>

using namespace std;

int main(void) {
	int x,y,cn=0,cnt=0,a;
	int arr[11];
	scanf("%d %d", &x, &y);
	for(a=0;a<x;a++)
		scanf("%d", &arr[a]);
	
	cn = a-1;
	while (y > 0) {
		if (y - arr[cn] >= 0) {
			y -= arr[cn];
			cnt++;
		}
		else
			cn--;
	}
	printf("%d", cnt);
	return 0;
}