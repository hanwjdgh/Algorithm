#include <iostream>
#include <ios>

using namespace std;

int arr[1000001];

int main(void){
    cin.tie(NULL);
	cout.tie(NULL);
	ios::sync_with_stdio(false);

	int n_case,t_case;
    int max;
    long long sum;
  	
    cin >> n_case;
    
    for(int i=1; i<=n_case;i++){
    	cin >> t_case;
        for(int j=0; j<t_case; j++)
        	cin >> arr[j];
        max=arr[t_case-1];
        sum=0;
        for(int j=t_case-2; j>-1; j--){
           	if(max < arr[j])
                max = arr[j];
            else
                sum += max -arr[j];
        }
        if (sum < 0)
			sum = 0;
        cout << "#"<<i<<" "<<sum<<"\n";
    }

    return 0;
}