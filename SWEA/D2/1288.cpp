#include <iostream>
#include <ios>

using namespace std;

int main(void){
    cin.tie(NULL);
	cout.tie(NULL);
	ios::sync_with_stdio(false);

	int t_case,num,cnt,temp;
    int arr[10],add;
    
    cin >> t_case;
    for(int i=1; i<=t_case; i++){
    	cin >> num;
		add = num;
        for(int j=0; j<10; j++)
            arr[j] = 0;
        cnt = 0;
        while(cnt < 10){
            temp = num;
        	while(temp > 0){
                if(arr[temp%10] ==0){
                    arr[temp%10] = 1;
                	cnt++;
                }
            	temp /= 10;
            }
            num += add;
        }
        cout<<"#"<<i<<" "<<num-add<<"\n";
    }

    return 0;
}