#include <iostream>
#include <ios>

using namespace std;

int main(void){
    cin.tie(NULL);
	cout.tie(NULL);
	ios::sync_with_stdio(false);

	int t_case,num;
    int arr[7][7];
    
    cin >> t_case;
    for(int i=1; i<=t_case; i++){
    	cin >> num;
        for(int a=0; a<num; a++)
        	for(int b=0; b<num; b++)
            	cin >> arr[a][b];

        cout<<"#"<<i<<"\n";
        for(int j=0; j<num; j++){
        	for(int a=0; a<num; a++)
                cout<<arr[num-1-a][j];    
            cout <<" ";         
            for(int a=0; a<num; a++)
                cout<<arr[num-1-j][num-1-a];    
            cout <<" ";        
             for(int a=0; a<num; a++)
                cout<<arr[a][num-1-j];    
            cout <<" ";
            cout<<"\n";
        }
    }
    
    return 0;
}