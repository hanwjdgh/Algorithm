#include <iostream>
#include <ios>
#include <algorithm>

using namespace std;

int main(void){
    cin.tie(NULL);
	cout.tie(NULL);
	ios::sync_with_stdio(false);

	int n, arr[200];

    cin >> n;
   
    for(int i=0; i<n;i++)
        cin >> arr[i];
    
    sort(arr,arr+n);

    cout << arr[n/2] << "\n";

    return 0;
}