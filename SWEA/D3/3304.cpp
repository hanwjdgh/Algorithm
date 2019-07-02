#include <iostream>
#include <ios>
#include <cstring>
#include <algorithm>

using namespace std;  

int dp[1001][1001]={0,};

int main(){
    cin.tie(NULL);
	cout.tie(NULL);
	ios::sync_with_stdio(false);

    int T;
    cin>>T;
    
    for(int test_case=1; test_case<=T; test_case++){
    	char arr[1000], brr[1000];
      
        cin >> arr >> brr;
        for(int i=1; i<=strlen(arr); i++){
        	for(int j=1; j<=strlen(brr); j++){
            	if (arr[i-1] == brr[j-1]) 
                    dp[i][j] = dp[i - 1][j - 1] + 1;
                else {
                    dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
                }
            }
        }

        cout << "#" << test_case << " " << dp[strlen(arr)][strlen(brr)] << "\n";
    }
	return 0;
}