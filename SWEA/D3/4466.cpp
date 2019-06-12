#include <iostream>
#include <ios>

using namespace std;

int main(int argc, char** argv){
    cin.tie(NULL);
	cout.tie(NULL);
	ios::sync_with_stdio(false);

	int test_case;
	int T;
    int N,K,hap=0;
    int i,j,temp;
    int arr[100];

	cin>>T;
	
	for(test_case = 1; test_case <= T; ++test_case){
        hap=0;
	
		cin >> N >> K;
        for(i=0; i<N; i++)
            cin >> arr[i];
        for (i = 0; i < N - 1; i++){
        	for (j = 0; j < N - 1 - i; j++){
            	if (arr[j] < arr[j + 1]){
                	temp = arr[j];
                	arr[j] = arr[j + 1];
                	arr[j + 1] = temp;
            	}
        	}
    	}
		for(i=0; i<K; i++)
            hap += arr[i];
        cout<<"#"<<test_case<<" "<<hap<<"\n";

	}
	return 0;
}