#include <iostream>
#include <ios>
#include <string> 
#include <algorithm>

using namespace std;

int main(void){
    cin.tie(NULL);
	cout.tie(NULL);
	ios::sync_with_stdio(false);
    
	string t_case;

    cin >> t_case;
    
    transform(t_case.begin(), t_case.end(), t_case.begin(), ::toupper);
    
    cout << t_case;

    return 0;
}