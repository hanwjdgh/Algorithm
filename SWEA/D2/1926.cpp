#include <iostream>
#include <ios>

using namespace std;
 
int main(void){
    cin.tie(NULL);
	cout.tie(NULL);
	ios::sync_with_stdio(false);

    int num;
    
    cin >> num; 
    for(int i=1; i<=num; i++){
        int temp=i;
        bool chk=0;
        if((temp/100)%3==0 && temp/100 !=0) { 
            cout << '-' ;
            chk=1;
        }
        temp%=100; 
        if((temp/10)%3==0 && temp/10 !=0) { 
            cout << '-'; 
            chk=1; 
        }
        temp%=10; 
        if( (temp/1)%3==0 && temp/1 !=0) {
            cout << '-';
            chk=1;
        }
        if(!chk) 
            cout << i ;
       cout << ' ' ;
    }

    return 0;
}