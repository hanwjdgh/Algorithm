#include <iostream>
#include <ios>
#include <string>

using namespace std;

int main(void){
    cin.tie(NULL);
	cout.tie(NULL);
	ios::sync_with_stdio(false);

	string t_case;

    cin >> t_case;
    
    for(int i=0; i<t_case.length();i++)
    	cout << t_case[i]-'A'+1<<" ";
    
    return 0;
}