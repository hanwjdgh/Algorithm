#include <iostream>
#include <ios>

using namespace std;

int main(void){
    cin.tie(NULL);
	cout.tie(NULL);
	ios::sync_with_stdio(false);

	int t_case,num,cnt;
    int soin[5] = {2,3,5,7,11};
    int chk[5] ={0,};

    cin >> t_case;
    
    for(int i=1; i<=t_case; i++){
    	cin>>num;

        cnt = 0;
        
        for(int j=0; j<5; j++)
            chk[j] =0;
        
        cout<<"#"<<i<<" ";
        
        while(cnt < 5 ){
        	if(num % soin[cnt] == 0){
                chk[cnt]++;
            	num /= soin[cnt];
            }
            else
                cnt++;
        }
        
        for(int j=0; j<5; j++)
            cout<<chk[j]<<" ";   
        cout<<"\n";
    }

    return 0;
}