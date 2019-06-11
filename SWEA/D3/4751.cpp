#include <iostream>
#include <ios>
#include <string>

using namespace std;
 
int main(void) {
    cin.tie(NULL);
	cout.tie(NULL);
	ios::sync_with_stdio(false);

    int T;
    
    cin >> T;

    for (int test_case = 1; test_case <= T; test_case++){
        char input[55] = { 0, };
        char answer[3][500];
        int i, j;
        int length;

        cin >> input;

        length = strlen(input);
 
        i = 0, j = 0;
 
        answer[0][j++] = '.';
        answer[0][j++] = '.';
        answer[0][j++] = '#';
        for (i = 0; i < length - 1; i++){
            answer[0][j++] = '.';
            answer[0][j++] = '.';
            answer[0][j++] = '.';
            answer[0][j++] = '#';
        }
        answer[0][j++] = '.';
        answer[0][j++] = '.';
        answer[0][j++] = '\0';
 
        for (i = 0, j = 0; i < length * 2; i++){
            answer[1][j++] = '.';
            answer[1][j++] = '#';
        }
        answer[1][j++] = '.';
        answer[1][j++] = '\0';
 
        for (i = 0, j = 0; i < length;){
            answer[2][j++] = '#';
            answer[2][j++] = '.';
            answer[2][j++] = input[i++];
            answer[2][j++] = '.';
        }
        answer[2][j++] = '#';
        answer[2][j++] = '\0';

        cout<<answer[0]<<"\n";
        cout<<answer[1]<<"\n";
        cout<<answer[2]<<"\n";
        cout<<answer[3]<<"\n";
        cout<<answer[4]<<"\n";
        
    }

    return 0;
}