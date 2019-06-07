#include <iostream>
#include <ios>
#include <cstring>
#include <bitset>

using namespace std;

int main(void){
    cin.tie(NULL);
	cout.tie(NULL);
	ios::sync_with_stdio(false);

    char Base[64] = {
    'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H',
    'I', 'J', 'K', 'L', 'M', 'N', 'O', 'P',
    'Q', 'R', 'S', 'T', 'U', 'V', 'W', 'X',
    'Y', 'Z', 'a', 'b', 'c', 'd', 'e', 'f',
    'g', 'h', 'i', 'j', 'k', 'l', 'm', 'n',
    'o', 'p', 'q', 'r', 's', 't', 'u', 'v',
    'w', 'x', 'y', 'z', '0', '1', '2', '3',
    '4', '5', '6', '7', '8', '9', '+', '/'
	};
	int t_case,sum,tmp;
    string str;
    string temp;
    
    cin>>t_case;
    for(int i=1; i<=t_case; i++){
    	cin>>str;
        
      temp="";
      for(int j=0; j<str.length(); j++){
      		for(int k=0; k<64; k++){
            	if(str[j] == Base[k]){
                    temp.append(bitset<6>(k).to_string());
                }
            }
      }
     cout<<"#"<<i<<" ";
     for(int j=0; j<temp.length(); j+=8){
         tmp = 1;
         sum = 0;
         for(int k=j+7; k>j-1; k--){
         	sum += (temp[k]-'0')*tmp;
            tmp *=2;
         }
         cout<<char(sum);
     }
        cout<<"\n";
    }

    return 0;
}