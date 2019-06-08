#include <iostream>
#include <ios>
#include <algorithm>
#include <vector>

using namespace std;

int main(void){

    cin.tie(NULL);
	cout.tie(NULL);
	ios::sync_with_stdio(false);

	int t_case,num,temp;
    vector<int> arr;

    cin >> t_case;
    
    for(int i=1; i<=t_case; i++){
    	cin >> num;
        arr.clear();
        for(int j=0; j<num; j++){
        	cin >> temp;
            arr.push_back(temp);
        }
        sort(arr.begin(),arr.end());
        cout<<"#"<<i<<" ";
          for(int j=0; j<num; j++){
        	cout<< arr[j]<<" ";
        }
        cout<<"\n";
    }

    return 0;
}