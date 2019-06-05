#include <iostream>
#include <ios>
 
using namespace std;
 
int main(void){
    cin.tie(NULL);
	cout.tie(NULL);
	ios::sync_with_stdio(false);

    int t_case, num, hap = 0;

    cin >> t_case;
    
    for(int i=0; i<t_case; i++){
        hap = 0;
        for(int j=0; j<10; j++){
            cin >> num;
            if(num%2==1)
                hap += num;
        }
        cout << i+1 << " " << hap <<"\n";
    }

    return 0;
}