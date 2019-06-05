#include <iostream>
#include <ios>

using namespace std;

int main(void){
    cin.tie(NULL);
	cout.tie(NULL);
	ios::sync_with_stdio(false);

	int num;
    
    cin >> num;
    
    cout << (num*(num+1))/2;

    return 0;
}