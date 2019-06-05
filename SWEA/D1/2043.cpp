#include <iostream>
#include <ios>

using namespace std;

int main(void){
    cin.tie(NULL);
	cout.tie(NULL);
	ios::sync_with_stdio(false);

    int P,K;
    
    cin >> P >> K;
    
    cout << P-K+1;

    return 0;
}