#include <iostream>
#include <ios>
#include <cstring>

using namespace std;

int main(int argc, char** argv){
    cin.tie(NULL);
	cout.tie(NULL);
	ios::sync_with_stdio(false);

	int test_case;
	int T;
    char card[4]={'S','D','H','C'};
    int cnt;
	
	cin>>T;
	
	for(test_case = 1; test_case <= T; ++test_case){
        char arr[1001];
        int dek[4][15]={0,};

        cnt=0;
        cin>>arr;
        cout<<"#"<<test_case<<" ";
        
        for(int i=0; i<strlen(arr); i+=3){
            int idx;
 			for(int j=0; j<4; j++)
            	if(card[j]==arr[i])
                    idx = j;
            if(dek[idx][((arr[i+1]-48)*10)+(arr[i+2]-48)]==0)
            	dek[idx][((arr[i+1]-48)*10)+(arr[i+2]-48)]++;
            else
                cnt++;
        }
        if(cnt>0)
            cout<<"ERROR"<<"\n";
        else{
            for(int i=0; i<4; i++){
                 cnt=0;
        		for(int j=1; j<14; j++)
            		if(dek[i][j]==0)
                        cnt++;
            	cout<<cnt<<" ";
        	}
            cout<<"\n";
        }
	}
	return 0;
}