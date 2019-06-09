#include <iostream>
#include <ios>

using namespace std;

int main(void){
    cin.tie(NULL);
	cout.tie(NULL);
	ios::sync_with_stdio(false);

	int t_case,num,max,idx;
    int arr[101];
    
   
    for(int i=1; i<= 10; i++){
        cin >> t_case;
        for(int j=0; j<101; j++)
        	arr[j] = 0;
       
    	for(int j=0; j<1000; j++){
        	cin >> num;
            arr[num]++;
        }	
        for(int j=0; j<101;j++){
        	if(j==0){
                max = arr[j];
            	idx = j;
            }
            if(max <=arr[j]){
                max = arr[j];
            	idx=j;
            }
        }
        cout<<"#"<<i<<" "<<idx<<"\n";
    }

    return 0;
}