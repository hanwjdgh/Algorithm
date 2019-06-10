#include<iostream>
#include <ios>

using namespace std;

int main(int argc, char** argv){
    cin.tie(NULL);
	cout.tie(NULL);
	ios::sync_with_stdio(false);

	int test_case;
	int T;
    int L,U,X;
	
	for(test_case = 1; test_case <= T; ++test_case){

		int L,U,X;
        
        cin >>L>>U>>X;
        cout<<"#"<<test_case<<" ";
        
        if(X>U)
			cout<<-1<<"\n";
        if(L<=X && X<=U)
            cout<<0<<"\n";
        if(X<L)
            cout<<L-X<<"\n";

	}

	return 0;
}