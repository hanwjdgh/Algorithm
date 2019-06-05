#include <iostream>
#include <ios>

using namespace std; 

int main(void){
    cin.tie(NULL);
	cout.tie(NULL);
	ios::sync_with_stdio(false);

    int t_case;

   	cin>>t_case;

    for(int i=1; i<=t_case; i++){
        int hap = 0;
        for(int j=0; j<10; j++){
            int num;
            cin >> num;
            hap += num;
        }
        cout << i<< " "<< (hap+5)/10 << "\n";
    }

    return 0;
}