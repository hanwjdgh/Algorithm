#include <iostream>
#include <ios>

using namespace std;

int main(void){
    cin.tie(NULL);
	cout.tie(NULL);
	ios::sync_with_stdio(false);

	int t_case, sum=0;

    cin >> t_case;
   
    while(t_case != 0){
    	sum += t_case % 10;
        t_case /= 10;
    }

    cout << sum << "\n";

    return 0;
}