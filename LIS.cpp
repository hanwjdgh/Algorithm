#include <iostream>
#include <ios>
#include <algorithm>

using namespace std;

int arr[1001], dp[1001], ans, N;

int main() {
    cin.tie(NULL);
    cout.tie(NULL);
    ios::sync_with_stdio(false);

    cin >> N;
    for(int i = 1; i <= N; ++i) {
        cin >> arr[i];
        int here = 0;
        for(int j = 1; j < i; ++j) {
            if(arr[i] > arr[j])
                here = max(here, dp[j]);
        }
        dp[i] = here + 1;
        ans = max(ans, dp[i]);
    }
    cout << ans;
    
    return 0;
}