#include <iostream>
#include <ios>
#include <cstdio>

#define Max 1000001

using namespace std;

int arr[Max];

int main(){
    cin.tie(NULL);
	cout.tie(NULL);
	ios::sync_with_stdio(false);

    arr[0] = -1;
    arr[1] = -1;
    for(int i=2; i<Max; i++)
        arr[i] = i;
    for(int i=2; i<Max; i++){
    	if(arr[i] != -1){
        	for(int j=2; i*j<Max;j++){
            	arr[i*j] = -1;
            }
        }
    }
    for(int i=0; i<Max; i++){
    	if(arr[i]!=-1)
            cout<<i<<" ";
    }
	return 0;
}