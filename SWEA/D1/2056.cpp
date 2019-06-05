#include <iostream>
#include <ios>
#include <string>
#include <cstdlib>

using namespace std;

int main(void){
    cin.tie(NULL);
	cout.tie(NULL);
	ios::sync_with_stdio(false);

    int t_case;
    string temp;
    int month[12] = {31,28,31,30,31,30,31,31,30,31,30,31};

    cin >> t_case;
    
    for(int i=1; i<=t_case; i++){
        cin >> temp;
        if(atoi(temp.substr(4,2).c_str())==0 || month[atoi(temp.substr(4,2).c_str())-1]< atoi(temp.substr(6,2).c_str()))
        	cout <<"#"<<i<<" "<<-1<<"\n";
        else
            cout << "#"<<i<<" "<< temp.substr(0,4)<<"/"<< temp.substr(4,2)<<"/"<<temp.substr(6,2)<<"\n";
    }

    return 0;
}