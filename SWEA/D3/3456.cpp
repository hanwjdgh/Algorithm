#include <iostream>
#include <ios>

using namespace std;

int main(int argc, char** argv){
    cin.tie(NULL);
	cout.tie(NULL);
	ios::sync_with_stdio(false);
    
	int test_case;
	int T;
    int a,b,c;
	
	cin>>T;
	
	for(test_case = 1; test_case <= T; ++test_case){
        cin >> a>>b>>c;
        cout<<"#"<<test_case<<" ";
        if(a==b && a==c)
			cout<<a<<"\n";
        if(a==b && a!=c)
            cout<<c<<"\n";
        if(a!=b && a==c)
            cout<<b<<"\n";
        if(a!=b && a!=c)
            cout<<a<<"\n";
	}

	return 0;
}