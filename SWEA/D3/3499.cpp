#include <iostream>
#include <ios>

using namespace std;

int main(int argc, char** argv){
    cin.tie(NULL);
	cout.tie(NULL);
	ios::sync_with_stdio(false);
    
	int test_case;
	int T;

	cin>>T;
	
	for(test_case = 1; test_case <= T; ++test_case){
        char arr[1000][81];
        int N;
        int interval;
        cin>>N;
        cout<<"#"<<test_case<<" ";
        for(int i=0; i<N; i++)
            cin >> arr[i];
        if(N%2==0)
        	interval = N/2;
        else
            interval = (N/2)+1;
        for(int i=0; i<N/2; i++){
        	cout<<arr[i]<<" "<<arr[i+interval]<<" ";
        }
        if(N%2==1)
        	cout<<arr[interval-1];
        
		cout<<"\n";

	}
	return 0;
}