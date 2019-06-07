#include <iostream>
#include <ios>
#include <string>

using namespace std;

int main(void){
    cin.tie(NULL);
	cout.tie(NULL);
	ios::sync_with_stdio(false);

	int t_case,cnt,po;
    
    string str,chk;
    cin >> t_case;
    for(int i=1; i<=t_case; i++){
        chk="";
        cin >> str;
        chk += str[0];
        cnt = po =1;
        while((cnt+po)<str.length()){
        	if(chk.compare(str.substr(cnt,po))!=0){
                chk = str.substr(0,cnt+1);
                po = chk.length();
                cnt++;
            }
            else{
                po = chk.length();
                cnt+=po;
            }   
        }
        cout<<"#"<<i<<" "<<chk.length()<<"\n";
    }

    return 0;
}