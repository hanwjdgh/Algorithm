#include <iostream>
#include <ios>

using namespace str;

int main(void){
    cin.tie(NULL);
	cout.tie(NULL);
	ios::sync_with_stdio(false);

	int t_case;
    
    cin >> t_case;

    for(int i=1; i<=t_case; i++){
        int max =0;
        for(int j=0; j<10; j++){
            int num;

            cin >> num;

           	max = (max==0)? num : (max <num)? num : max;
        }
        cout<< i << max << "\n";
    }

    return 0;
}