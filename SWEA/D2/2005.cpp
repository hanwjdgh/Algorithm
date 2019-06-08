#include <iostream>
#include <ios>

using namespace std;

int main(void){
    cin.tie(NULL);
	cout.tie(NULL);
	ios::sync_with_stdio(false);

	int arr[10][10]={1,0};
    int num,t_case;
    
    cin >> t_case;
    for(int i=1; i<=t_case;i++){
        cin >> num;
        for(int a=0; a<num; a++)
            for(int b=0; b<=a; b++)
                arr[a][b] = (b==0) ? 1 :arr[a-1][b-1]+arr[a-1][b];
        
        cout<<"#"<<i<<"\n";
        for(int a=0; a<num; a++){
            for(int b=0; b<=a; b++)
                cout<<arr[a][b]<<" ";
        	cout<<"\n";
        }
    }

    return 0;
}