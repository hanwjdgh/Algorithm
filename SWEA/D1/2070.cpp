#include <iostream>
#include <ios>
#include <cstdio>

using namespace std;


int main(void){
    int t_case;

    cin >> t_case;
    
    for(int i=1; i<=t_case; i++){
    	int a,b;
        
        cin >> a >> b;
        
        (a > b) ? printf("#%d >\n",i) : ((a<b) ? printf("#%d <\n",i) : printf("#%d =\n",i));
    }

    return 0;
}