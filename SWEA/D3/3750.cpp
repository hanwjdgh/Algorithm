#include <iostream>
#include <ios>

using namespace std;

int main(int argc, char** argv){
    cin.tie(NULL);
	cout.tie(NULL);
	ios::sync_with_stdio(false);

	int test_case;
	int T;
	
    cin >> T;

	for(test_case = 1; test_case <= T; ++test_case){
        unsigned long int num;

        cin >> num;

        cout << "#" << test_case << " ";

        while(1){
            if(num<10){
                cout << num << "\n";
            	break;
            }
            else{
                int temp=0;
                while(num!=0){
                    temp += num %10;
                    num /= 10;
                }
                num = temp;
            }
        }


	}
	return 0;
}