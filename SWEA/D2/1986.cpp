#include <iostream>
#include <ios>

using namespace std;

int main(void){
    cin.tie(NULL);
	cout.tie(NULL);
	ios::sync_with_stdio(false);

	int t_case,num,hap;
    
    cin >> t_case;
    
    for(int i=1; i<=t_case; i++){
    	cin >> num;
        hap = 0;
        for(int j=1; j<=num; j++)
        	hap += (j%2==1) ? j : -j;
        cout<<"#"<<i<<" "<<hap<<"\n";
    }

    return 0;
}