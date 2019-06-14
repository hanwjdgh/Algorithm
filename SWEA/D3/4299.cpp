#include <iostream>
#include <ios>

using namespace std;

int main(int argc, char** argv){
    cin.tie(NULL);
	cout.tie(NULL);
	ios::sync_with_stdio(false);

	int test_case;
	int T;
    int D,H,M;
    int val,temp;
	
	cin>>T;
	
    val = 11*1440+11*60+11;
	for(test_case = 1; test_case <= T; ++test_case){

		cin >> D >> H >> M;
        temp = D*1440+H*60+M;
        cout<<"#"<<test_case<<" ";
        if(val > temp)
            cout<<"-1"<<"\n";
        else
            cout<<temp-val<<"\n";


	}
	return 0;
}