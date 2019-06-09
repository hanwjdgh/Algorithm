#include <iostream>
#include <ios>
#include <algorithm>
#include <string>

using namespace std;

int main(void){
    cin.tie(NULL);
	cout.tie(NULL);
	ios::sync_with_stdio(false);

	int t_case,num,idx;
    string str[10] ={"D0", "C-", "C0", "C+", "B-", "B0", "B+", "A-", "A0", "A+"};
    double arr[100],hap,f_val;
    double per[3] = {0.35,0.45,0.20};
    int N,K;

    cin >> t_case;
    
    for(int i=1; i<=t_case; i++){
    	cin >> N >>K;
        for(int j=0; j<N; j++){
            hap=0;
        	for(int k=0; k<3; k++){
            	cin >> num;
                hap += num * per[k];
            }
            if(j==K-1)
                f_val = hap;
            arr[j] = hap;
        }
        sort(arr,arr+N);
        idx = find( arr, arr + N, f_val ) - arr;
        cout<<"#"<<i<<" "<<str[idx/(N/10)]<<"\n";
    }

    return 0;
}