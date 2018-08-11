#include <iostream>
#include <ios>
#include <string>

using namespace std;
int N, chk, cnt;
string ans;

void backtrack() {
	if (cnt == N) {
		if (chk == 0) {
			for (int i = 0; i < N; i++)
				cout << ans[i];
			cout << endl;
			chk = 1;
		}
		return;
	}
	if (chk == 1)
		return;

	for (int i = 1; i <= 3; i++) {
		bool error = false;
		cnt++;
		ans.push_back(i + '0');
		for (int j = 1; j <= cnt / 2; j++) {
			if (equal(ans.end() - j, ans.end(), ans.end() - j * 2))
				error = true;
		}
		if (!error) 
			backtrack();	
		cnt--;
		ans.pop_back();		
	}
}

int main() {
	cin.tie(NULL);
	ios::sync_with_stdio(false);

	cin >> N;
	ans.push_back(1 + '0');
	cnt++;
	backtrack();
	return 0;
}