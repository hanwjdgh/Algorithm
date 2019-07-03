#include <iostream>
#include <ios>

using namespace std;
 
int main(void) {
    cin.tie(NULL);
	cout.tie(NULL);
	ios::sync_with_stdio(false);

    int T;
    long int N, S[3];
 
    cin >> T;

    for(int test_case=1; test_case<=T; test_case++) {
        cin >> N;
        
        S[0] = N*(N+1)/2;
        S[2] = S[0] * 2;
        S[1] = S[2] - N;

        cout << "#" << test_case << " " << S[0] << " " << S[1] << " " << S[2] << "\n";
    }
 
    return 0;
}