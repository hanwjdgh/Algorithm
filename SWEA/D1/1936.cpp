#include <iostream>
#include <ios>
#include <cstdio>

using namespace std;

int main(void){
    cin.tie(NULL);
	cout.tie(NULL);
	ios::sync_with_stdio(false);

    int a,b;
    
    cin >> a>> b;
    
    (a==1) ? (b==2)? printf("B"): printf("A") : 0;
    
    (a==2) ? (b==3)? printf("B"): printf("A") : 0;
    
    (a==3) ? (b==1)? printf("B"): printf("A") : 0;

    return 0;
}