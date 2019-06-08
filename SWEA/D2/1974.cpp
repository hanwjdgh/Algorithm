#include <iostream>
#include <ios>

using namespace std;

int main(void){
    cin.tie(NULL);
	cout.tie(NULL);
	ios::sync_with_stdio(false);

	int t_case,cnt;
    int arr[9][9];
    int mat[9]={0,}, row[9]={0,}, col[9]={0,};

    cin >> t_case;
    for(int i=1; i<=t_case;i++){
        for(int a=0; a<9; a++)
        	for(int b=0; b<9; b++)
            	cin >> arr[a][b];
          cnt = 0;

          for(int a=0; a<9; a++){    
        	for(int b=0; b<9; b++){

              	if(a%3==0 && b%3==0){
                    for(int x=0; x<9; x++)
                    	mat[x] = 0;
                    for(int j=a; j<a+3; j++){
                        for(int k=b; k<b+3; k++){
                            if(mat[arr[j][k]-1] ==0)
                                mat[arr[j][k]-1] = 1;
                            else
                                cnt++;
                        }
                    }
                }

                if(a==0){
                    for(int x=0; x<9; x++)
                    	col[x] = 0;
                    for(int j=0; j<9; j++){
                    	if(col[arr[b][j]-1] == 0)
                            col[arr[b][j]-1] = 1;
                        else
                            cnt++;
                    }
                }

                if(b==0){
                     for(int x=0; x<9; x++)
                    	row[x] = 0;
                     for(int j=0; j<9; j++){
                    	if(row[arr[j][a]-1] == 0)
                            row[arr[j][a]-1] = 1;
                        else
                            cnt++;
                    }
                }
            }
          }

        cnt = (cnt >0)? 0: 1;
        cout<<"#"<<i<<" "<<cnt<<"\n";
    }
    
    return 0;
}