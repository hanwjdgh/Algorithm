#include <iostream>
#include <ios>

using namespace std;

int main(int argc, char** argv){
    cin.tie(NULL);
	cout.tie(NULL);
	ios::sync_with_stdio(false);

	int test_case;
	int T;

    cin >> T;

    int N;
	for(test_case = 1; test_case <= T; ++test_case){
        long long arr[101];
        
        cin >> N;
        
        cout<<"#"<<test_case<<" ";

        arr[1] = arr[2] = arr[3] = 1;
        arr[4] = arr[5] = 2;
        arr[6] = 3;
        for(int i=7; i<=N; i++)
            arr[i] = arr[i-5]+arr[i-1];    
             
        cout<<arr[N]<<"\n";
	}
	return 0;
}