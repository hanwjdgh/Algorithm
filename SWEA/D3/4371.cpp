#include <iostream>
#include <ios>

using namespace std;

int main(int argc, char** argv){
    cin.tie(NULL);
	cout.tie(NULL);
	ios::sync_with_stdio(false);
    
	int test_case;
	int T;
    int num,cnt,chk;
    int arr[5000];
    int jugi[5000];

	cin>>T;
	
	for(test_case = 1; test_case <= T; ++test_case){
        cin >>num;
        cnt=0;
        for(int i=0; i<num; i++){
        	cin >> arr[i];
        }
		for(int i=1;i<num;i++){
        	if(cnt==0){
            	jugi[cnt++] = arr[i]-arr[0];
            }
            else{
                chk=0;
            	for(int j=0; j<cnt;j++){
                	if((arr[i]-arr[0])%jugi[j]==0)
                        chk++;
                }
                if(chk==0)
                    jugi[cnt++] = arr[i]-arr[0];
            }
        }
		cout<<"#"<<test_case<<" "<<cnt<<"\n";
	}
	return 0;
}