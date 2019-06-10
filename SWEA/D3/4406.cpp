#include <iostream>
#include <ios>

using namespace std;

int main(int argc, char** argv){
    cin.tie(NULL);
	cout.tie(NULL);
	ios::sync_with_stdio(false);

	int test_case;
	int T;
    char temp[5] = {'a','e','i','o','u'};

	cin>>T;
	
	for(test_case = 1; test_case <= T; ++test_case){
		char arr[50]={0,};

        cin>>arr;
        
        cout<<"#"<<test_case<<" ";
		
        for(int i=0;i<50;i++){
        	if(arr[i]>='a' && arr[i]<='z'){
                int cnt=0;
                for(int j=0;j<5;j++){
                    if(arr[i]==temp[j])
                        cnt++;
                }
                if(cnt==0)
                    cout<<arr[i];
            }
            else
                break;
        }
		cout<<"\n";
      
	}

	return 0;
}