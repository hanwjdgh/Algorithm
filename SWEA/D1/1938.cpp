#include <iostream>
#include <ios>

using namespace std;

int main(void){
    cin.tie(NULL);
	cout.tie(NULL);
	ios::sync_with_stdio(false);

	int a, b;

    cin >> a>> b;

    cout<< a+b <<"\n";
    cout<< a-b <<"\n";
    cout<< a*b <<"\n";
    cout<< a/b <<"\n";

    return 0;
}