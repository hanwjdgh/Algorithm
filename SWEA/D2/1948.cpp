#include <iostream>
#include <ios>

using namespace std;

int main(void){
    cin.tie(NULL);
	cout.tie(NULL);
	ios::sync_with_stdio(false);

	int t_case,sum;
    int mon[12]={31,28,31,30,31,30,31,31,30,31,30,31};
    int arr[4];
    
    cin >> t_case;
    for(int i=1; i<=t_case; i++){
        sum = 0;
    	for(int j=0; j<4; j++)
            cin >> arr[j];
        
        if(arr[2]-arr[0] !=0){
            for(int j=arr[0]+1; j<arr[2]; j++)
                sum += mon[j-1];       
  	    sum += mon[arr[0]-1] - arr[1] + 1;
        sum += arr[3] ;
        }
        else{
        	sum+= arr[3]-arr[1] +1;
        }
        
        cout<<"#"<<i<<" "<<sum<<"\n";
    }

    return 0;
}