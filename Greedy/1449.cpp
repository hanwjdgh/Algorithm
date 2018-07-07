#include<cstdio>
#include<algorithm>

using namespace std;

int n, l, a[1000], r = 1;

int main() {
    scanf("%d%d", &n, &l);
    for (int i = 0; i < n; i++) 
    scanf("%d", a + i);
    sort(a, a + n);
    for (int i = 0, t = 0; i < n; i++) 
        if (a[i] - a[t] >= l) 
            t = i, r++;
    printf("%d", r);
    return 0;
}