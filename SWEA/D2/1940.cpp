#include <iostream>
#include <ios>

using namespace std;

int main(void){
    cin.tie(NULL);
	cout.tie(NULL);
	ios::sync_with_stdio(false);

	int t_case, num,sum;
    int n_case, speed,n_speed;
    
    cin >> t_case;
    for(int i=1; i<=t_case; i++){
    	cin >> num;
        n_speed =sum= 0;
        for(int j=0; j<num; j++){
        	cin >> n_case;
            if(n_case == 1){
            	cin>>speed;
                n_speed += speed;
            }
            if(n_case == 2){
                cin>>speed;
                if(n_speed >= speed)
            		n_speed -= speed;
            }
		   sum +=n_speed;
        }
        cout<<"#"<<i<<" "<<sum<<"\n";
    }

    return 0;
}