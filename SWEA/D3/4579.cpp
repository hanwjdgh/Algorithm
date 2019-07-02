#include <iostream>
#include <ios>
#include <string>
 
char str[21];
const char rStr[2][10] = {  "Not exist","Exist"};
 
int main(){
    cin.tie(NULL);
	cout.tie(NULL);
	ios::sync_with_stdio(false);

    int t;

    cin >> t;

    for (int i = 1; i <= t; i++){
        cin >> str;

        int len = strlen(str);
 
        bool res = true;
        for (int i = 0; i < len / 2; i++){
            if (str[i] == '*' || str[len - i - 1] == '*') 
                break;
            if (res = str[i] == str[len - i - 1]) 
                continue;
        }

        cout << "#" << i << " " << rStr[res] << "\n";
    }
    return 0;
}
