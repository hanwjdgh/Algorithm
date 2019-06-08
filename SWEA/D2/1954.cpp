#include <iostream>
#include <ios>

using namespace std;

int main(void){
    cin.tie(NULL);
	cout.tie(NULL);
	ios::sync_with_stdio(false);

	int t_case,limit,num,cnt;
    int arr[10][10];
    int delta,i,j;

    cin >> t_case;
    for(int k=1; k<=t_case; k++){
    	cin >> limit;
        i=0,j=-1;
        cnt = limit;
        num=delta=1;
        
        while(1){
            for(int p=0; p<limit; p++){
                j=j+delta;
                arr[i][j]=num;
                num++;
            }
            limit--;
            if(limit<0) break;
            for(int p=0; p<limit; p++){
                i=i+delta;
                arr[i][j]=num;
                num++;
            }

            delta=-delta;
    	}
        
        cout<<"#"<<k<<"\n";      
        for(int a=0; a<cnt; a++){
            for(int b=0; b<cnt; b++)
                cout<<arr[a][b]<<" ";
            cout<<"\n";
        }
    }

    return 0;
}