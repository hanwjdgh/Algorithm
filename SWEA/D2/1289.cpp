#include <iostream>
#include <ios>
#include <string>
#include <cstdio>

using namespace std;

int main(void){
    cin.tie(NULL);
	cout.tie(NULL);
	ios::sync_with_stdio(false);

	int t_case,chk;
    string str;
    
    cin >> t_case;
    for(int i=1; i<=t_case; i++){
    	cin >> str;
        chk=0;
        for(int j=0; j< str.length()/2 ;j++){
        	if(str[j] != str[str.length()-1-j]){
                chk++;
            	break;
            }
        }
        (chk != 0) ? printf("#%d 0\n",i) : printf("#%d 1\n",i); 
    }

    return 0;
}