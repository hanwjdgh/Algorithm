#include <iostream>
#include <ios>
#include <algorithm>

using namespace std;

int main(void){
    cin.tie(NULL);
	cout.tie(NULL);
	ios::sync_with_stdio(false);

    int t_case,hap;
    int arr[10];
    
    cin >> t_case;
    
    for(int i=1; i<=t_case; i++){
        hap = 0;
        for(int j=0; j<10;j++)
            cin >> arr[j];     
        sort(arr,arr+10);
        for(int j=1; j<9;j++)
            hap += arr[j];
        cout<<"#"<<i<<" "<<(hap+4)/8<<"\n";
    }

    return 0;
}