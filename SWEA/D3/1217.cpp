#include <iostream>
#include <ios>

using namespace std;

int mul(int cnt, int a, int b, int cur){
	if(cnt==b)
        return cur;
    else
        mul(cnt+1, a, b, cur*a);
}

int main() {
    cin.tie(NULL);
    cout.tie(NULL);
    ios::sync_with_stdio(false);

    for(int t=1; t<= 10; t++){
    	int N, a, b;
        
        cin >> N >> a >> b;
        
        cout<<"#"<<t<<" "<<mul(1,a,b,a)<<endl;
    }
    
    return 0;
}