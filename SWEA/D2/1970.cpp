#include <iostream>
#include <ios>

using namespace std;

int main(void){
    cin.tie(NULL);
	cout.tie(NULL);
	ios::sync_with_stdio(false);

	int t_case,num,cnt;
    int money[8]={50000,10000,5000,1000,500,100,50,10};
    int arr[8];
    
    cin>> t_case; 
    for(int i=1; i<=t_case; i++){
    	cin >> num;
        
        for(int a=0; a<8; a++)
            arr[a] = 0;
        cnt =0;
        num = (num/10) *10;
        while(num >0){
        	arr[cnt] = num/money[cnt];
            num %= money[cnt++];
        }
        
        cout<<"#"<<i<<"\n";
        for(int a=0; a<8; a++)
            cout<<arr[a]<< " ";
       cout<<"\n";
    }

    return 0;
}