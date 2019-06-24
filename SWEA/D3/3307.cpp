#include <iostream>
#include <ios>
#include <algorithm> 

using namespace std;

int main(){
    cin.tie(NULL);
	cout.tie(NULL);
	ios::sync_with_stdio(false);

    int T;

    cin >> T;

    int N;
    for(int test_case=1; test_case<=T; test_case++){
    	int arr[1000],dp[1000]={1,};

        cin >> N;
        
        int m_val=0;
        for(int i=0; i<N;i++){
            cin >> arr[i];
          
            dp[i] = 1;
        	for(int j=0; j<i; j++){
            	if(arr[i]>arr[j]){
                	dp[i] = max(dp[i],dp[j]+1);
                }
            }
        }

        int val=0;
        for(int i=0; i<N; i++)
            val = max(val,dp[i]);
        cout << "#" << test_case << " " << val << "\n";
    }
    
	return 0;
}