#include <iostream>
#include <ios>
#include <algorithm>

using namespace std;
 
int t,n,k,v[101],c[101],d[1001][101];
 
int main(){
    cin.tie(NULL);
	cout.tie(NULL);
	ios::sync_with_stdio(false);

    cin >> t;

    for(int T=1;T<=t;T++) {

        cin >> n >> k;

        for(int i=1;i<=n;i++)
            cin >> v[i] >> c[i];
            
        for(int i=1;i<=k;i++){
            for(int j=1;j<=n;j++){
                if(i>=v[j]) 
                    d[i][j]=max(d[i][j-1],d[i-v[j]][j-1]+c[j]);
                else 
                    d[i][j]=d[i][j-1];
            }
        }
        cout << "#" << T << " " << d[k][n] << "\n";
    }
    return 0;
}