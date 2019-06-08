#include <iostream>
#include <ios>

using namespace std;

int main(void){
    cin.tie(NULL);
	cout.tie(NULL);
	ios::sync_with_stdio(false);

	int t_case,hap,time;
    int arr[4];

    cin >> t_case;
    for(int i=1; i<=t_case; i++){
    	for(int j=0; j<4; j++)
        	cin >> arr[j];
        hap=0;
        for(int j=0; j<4; j++){
        	if(j%2==0)
                hap += arr[j] * 60;
            else
                hap +=arr[j];
           
        }
        time = (((hap/60)%12)==0) ? 12: ((hap/60)%12);
    cout<<"#"<<i<<" "<<time<<" "<<hap%60<<"\n";
    }

    return 0;
}