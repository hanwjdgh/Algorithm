#include <iostream>
#include <ios>

using namespace std;

int main(void){
    cin.tie(NULL);
	cout.tie(NULL);
	ios::sync_with_stdio(false);

	int t_case, a,b;

    cin >> t_case;
    
    for(int i=1; i<=t_case; i++){
    	cin >> a >> b;
        cout <<"#"<<i<<" "<< a/b<<" " << a%b<<endl;
    }

    return 0;
}