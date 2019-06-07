#include <iostream>
#include <ios>

using namespace std;

int main(void){
    cin.tie(NULL);
	cout.tie(NULL);
	ios::sync_with_stdio(false);

	int t_case,num1,num2;
    int min;
    int arr[5];
    
    cin >> t_case;
    for(int i=1; i<=t_case; i++){
    	for(int j=0; j<5; j++)
        	cin >> arr[j];

        num1 = arr[0] * arr[4];
        if(arr[2] >= arr[4])
            num2 = arr[1];
        else
            num2 = arr[1] + (arr[4]-arr[2])*arr[3];
        min = (num1<num2)?num1:num2;
        cout<<"#"<<i<<" "<<min<<"\n";
    }

    return 0;
}