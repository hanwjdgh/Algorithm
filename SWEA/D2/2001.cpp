#include <iostream>
#include <ios>

using namespace std;

int main(void){
    cin.tie(NULL);
	cout.tie(NULL);
	ios::sync_with_stdio(false);

	int t_case,max,a,b,c,d;
    int N,M;
    
    cin >> t_case;
    for(int i=1; i<=t_case; i++){
    	cin >> N>>M;
        max = 0;
        int arr[15][15];
        for(int a=0; a<N;a++){
        	for(int b=0;b<N;b++){
            	cin >> arr[a][b];
            }
        }
       for(a=0;a<N-M+1;a++){
          for(b=0;b<N-M+1;b++){
              int hap=0;
              for(c=0;c<M;c++){
          			for(d=0;d<M;d++)
                        hap+= arr[a+c][b+d];                    
              }
              max = (max==0)?hap:(max<hap)? hap:max;
          }
       }
     cout<<"#"<<i<<" "<<max<<"\n";
    }

    return 0;
}