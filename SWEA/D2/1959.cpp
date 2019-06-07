#include <iostream>
#include <ios>

using namespace std;

int main(void){
    cin.tie(NULL);
	cout.tie(NULL);
	ios::sync_with_stdio(false);

	int t_case,max,temp;
    int N,M;
    int arr1[20],arr2[20];

    cin >> t_case;
    for(int i=1; i<=t_case; i++){
    	cin >>N>>M;
        max =0;
        for(int j=0; j<N; j++)
            cin >> arr1[j];
        for(int j=0; j<M; j++)
            cin >> arr2[j];
        
        if(N>M){
        	for(int a=0; a<N-M+1; a++){
                temp = 0;
            	for(int b=0;b<M;b++)
                	temp += arr2[b] * arr1[a+b];               
                max = (max < temp)? temp:max;
            }
        }
        else if(N<M){
        	for(int a=0; a<M-N+1; a++){
                temp = 0;
            	for(int b=0;b<N;b++)
                	temp += arr1[b] * arr2[a+b];                 
                max = (max < temp)? temp:max;
            }
        }
        else{
        	for(int a=0; a<N; a++)
                max += arr1[a] * arr2[a];
        }
        cout<<"#"<<i<<" "<<max<<"\n";
    }

    return 0;
}