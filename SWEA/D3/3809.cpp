#include<iostream>
#include <ios>
#include<vector>
#include<string>
#include<cmath>

using namespace std;

bool used[10001];
vector<char> v;
int n;

void init(){
    v.assign(n,0);
 
    for (int i = 0; i < 1001; i++){
        used[i] = false;
    }
}

int check(int k){
 
    for (int i = 0; i < pow(10, k);i++){
        if (!used[i]){
            return i;
        }
    }
 
    return -1;
}

void go(int k){
    for (int i = 0; i+k < n; i++){
        string s = "";
        s += v[i];
 
        for (int j = 1; j <= k; j++){
            s += v[j + i];
        }
 
        used[stoi(s)] = true;
    }
}

int main(){
    cin.tie(NULL);
	cout.tie(NULL);
	ios::sync_with_stdio(false);

    int tc;
    cin >> tc;
 
    for (int t = 1; t <= tc; t++){
        cin >> n;
        init();
        for (int i = 0; i < n; i++){
            cin >> v[i];
        }
 
        for (int i = 0; i < 4; i++){
            go(i);
            int k = check(i);
            if (k != -1){
                cout << "#" << t << " " << k << "\n";
                break;
            }
        }
    }
    return 0;
}
