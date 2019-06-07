#include <iostream>
#include <ios>

using namespace std;

int main(void){
    cin.tie(NULL);
	cout.tie(NULL);
	ios::sync_with_stdio(false);

	int t_case,N,K,cnt,r_chk,c_chk;
    int arr[16][16]={0,};
    
    cin >>t_case;
    
    for(int i=1; i<=t_case; i++){
    	cin>>N>>K;
        cnt = 0;
        for(int j=1;j<=N;j++)
        	for(int k=1; k<=N; k++)
            	cin >> arr[j][k];
    	 for(int j=1;j<=N;j++){
        	for(int k=1; k<=N; k++){
                r_chk=c_chk=0;
            	if(arr[j][k] == 1){
                    if(arr[j][k-1]==0){
                        for(int a=k; a<=N; a++){
                            if(arr[j][a]==1){
                                r_chk++;
                            }
                            else
                                break;
                        }
                        if(r_chk == K){
                            cnt++;
                            r_chk=0;
                        }
                    }
                    
                    if(arr[j-1][k]==0){
                        for(int a=j; a<=N; a++){
                            if(arr[a][k] == 1)
                                c_chk++;
                            else
                                break;
                        }
                          if(c_chk == K){
                            cnt++;
                            c_chk=0;
                        }
                    }
                }
                
            }
         }
        cout<<"#"<<i<<" "<<cnt<<"\n";
    }

    return 0;
}