#include <iostream>
#include <ios>
#include <string>
#include <algorithm>

using namespace std;

int main(int argc, char** argv){
    cin.tie(NULL);
	cout.tie(NULL);
	ios::sync_with_stdio(false);

	int test_case;
	int T;

    cin >> T;

    int temp,tmp,na;
	for(test_case = 1; test_case <= T; ++test_case)
    {
		string arr,brr,crr;
        string tt;

        cin >> arr >> brr;
        
        int a = arr.length(), b=brr.length();
        if (a<b){
        	tt=brr;
            brr = arr;
            arr = tt;
        }

        int len = max(a,b);
        int m_val = min(a,b);
        
        temp=tmp=na=0;
        for(int i=0; i<len-m_val; i++)
            brr = "0"+brr;

        for(int i=len-1; i > -1; i--){
            if(i>=(len-m_val)){
            	temp = ((arr[i]-'0') + (brr[i]-'0')+na)%10;
                tmp = ((arr[i]-'0') + (brr[i]-'0')+na)/10;
                crr.push_back(temp+'0');
            }
            else{
            	temp = ((arr[i]-'0')+na)%10;
                tmp = ((arr[i]-'0')+na)/10;
                crr.push_back(temp+'0');
            }
            na = tmp;
        }
        if(tmp != 0)
            crr.push_back(tmp+'0');
        reverse(crr.begin(),crr.end());
        
        cout<<"#"<<test_case<<" "<<crr<<endl;
	}
	return 0;
}