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
		int a,b;
        cin>>a>>b;
        cout<<"#"<<test_case<<" "<<b-(a-b)<<" "<<a-b<<"\n";


	}
	return 0;
}