#include <cstdio>
#include <ios>

using namespace std;
 
int main(){
    cin.tie(NULL);
	cout.tie(NULL);
	ios::sync_with_stdio(false);

    int T;

    cin >> T;
    
    for(int t_case=1; t_case<=T; t_case++){

        cout << "#" << t_case << " ";

        int a,b,c,d;
        
        cin >> a >> b >> c >> d;

        if(a*d>b*c)
            cout << "ALICE" << "\n";
        else if(a*d==b*c)
            cout << "DRAW" << "\n";
        else
            cout << "BOB" << "\n";
    }
    return 0;
}