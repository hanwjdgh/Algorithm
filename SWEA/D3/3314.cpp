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
	
    int arr[5];
	for(test_case = 1; test_case <= T; ++test_case){
        int hap=0;
        for(int i=0; i<5;i++)
            cin>>arr[i];
        for(int i=0; i<5;i++){
        	if(arr[i] < 40)
                arr[i]=40;
            hap+=arr[i];
        }
		cout<<"#"<<test_case<<" "<<hap/5<<"\n";

	}

	return 0;
}