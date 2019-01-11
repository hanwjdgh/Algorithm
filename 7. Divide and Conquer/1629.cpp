#include <iostream>
#include <cstdio>
#include <cmath>

using namespace std;
long long C;
long long multiple(long long par,long long ch) {
    int ret=0;
	if(ch==1)
        return par%C;
    int mid = ch/2;
    if(ch%2==0)
        ret = (multiple(par,mid)*multiple(par,mid))%C;
    else
        ret = (multiple(par,mid)*multiple(par,mid+1))%C;
    return ret;
}
int main() {
	long long A, B;
	scanf("%lld %lld %lld", &A, &B, &C);
	printf("%lld\n",multiple(A, B));
	return 0;
}