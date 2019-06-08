#include <iostream>
#include <ios>
#include <cmath>

using namespace std;

int main(void){
    cin.tie(NULL);
	cout.tie(NULL);
	ios::sync_with_stdio(false);

	int t_case,num,cnt,min;
    int arr[1000];
    
    cin>> t_case;
    
    for(int i=1; i<=t_case; i++){
    	cin >> num;
        cnt=min=0;
        for(int j=0; j<num; j++)
            cin >> arr[j];
        for(int j=0; j<num; j++){
        	if(min ==0 )
                min = abs(arr[j]);
            if(min > abs(arr[j]))
                min = abs(arr[j]);
        }
        for(int j=0; j<num; j++){
        	if(abs(arr[j])==min)
                cnt++;
        }
 	    cout<<"#"<<i<<" "<<min<<" "<<cnt<<endl;
    }

    return 0;
}