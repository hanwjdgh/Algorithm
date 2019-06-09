#include <iostream>
#include <ios>

using namespace std;

int main(void){
	cin.tie(NULL);
	cout.tie(NULL);
	ios::sync_with_stdio(false);

    int t_case,num,cnt,seq;
    int arr[26]={0},temp,hap;
    int alarr[26]={0,};
	char alpha;
    
    cin>>t_case;
    
    for(int i=1;i<=t_case; i++){
    	cin >> num;
        hap =cnt= seq = 0;
        for(int j=0; j<num; j++){
        	cin >> alpha>>temp;
         	alarr[j] = alpha-'A';
            arr[j] = temp;
            hap += temp;
        }

   		cout<<"#"<<i<<endl;
        for(int j=0; j< ((hap-1)/10)+1; j++){
        	for(int k=0; k<10; k++){
                 if(cnt == arr[seq]){
                    cnt=0;
                    seq++;
                }
                if(seq==num)
               		 break;
            	cout<<char(alarr[seq]+'A');
                cnt++;
            	
            }
            cout<<"\n";
        }
    }
    return 0;
}