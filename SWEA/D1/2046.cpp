#include <iostream>
#include <ios>

using namespace std;

int main(void){
    cin.tie(NULL);
	cout.tie(NULL);
	ios::sync_with_stdio(false);

	int num;
    
    cin >> num;
    
    for(int i=0; i<num; i++)
        cout << "#";

    return 0;
}