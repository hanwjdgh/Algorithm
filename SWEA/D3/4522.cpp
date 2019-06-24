#include <iostream>
#include <ios>
#include <cstring>

using namespace std;

int main(int argc, char** argv){
    cin.tie(NULL);
	cout.tie(NULL);
	ios::sync_with_stdio(false);

	int test_case;
	int T;
	
    cin >> T;

	for(test_case = 1; test_case <= T; ++test_case){
		char arr[21];

        cin >> arr;
        
        int cnt=0;
        for(int i=0; i<strlen(arr)/2;i++){
			if(arr[i]=='?' || arr[strlen(arr)-i-1]=='?')
                continue;
        	if(arr[i]!=arr[strlen(arr)-i-1])
                cnt++;
        }

        cout << "#" << test_case << " ";

        if(cnt==0)
            cout << "Exist" << "\n";
        else
            cout << "Not exist" << "\n";
	}

	return 0;
}