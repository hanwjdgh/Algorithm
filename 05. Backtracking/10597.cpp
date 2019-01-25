#include <iostream>
#include <ios>
#include <string>

using namespace std;

string num;
int visit[51] = { 0, }, chk = 0;
int ans[51] = { 0, };
int leng, cnt, idx=0;

void backtrack(int x) {
	if (chk)
		return;

	if (x == leng) {
		for (int i = 0; i < cnt; i++)
			cout << ans[i] << " ";
		chk = 1;
		return;
	}

	int ftmp = num[x] - '0';
	if (ftmp > 0 && !visit[ftmp]) {	
		visit[ftmp] = 1;
		ans[idx] = ftmp;
		idx++;
		backtrack(x + 1);
		visit[ftmp] = 0;
		idx--;
	}
	if (num[x+1]) {
		int tmp = ftmp * 10 + num[x + 1] - '0';
		if (tmp > 0 && tmp <= cnt && !visit[tmp]) {
			visit[tmp] = 1;
			ans[idx] = tmp;		
			idx++;
			backtrack(x + 2);
			visit[tmp] = 0;
			idx--;
		}
	}
}

int main() {
	cin.tie(NULL);
	ios::sync_with_stdio(false);

	cin >> num;

	leng = num.length();

	for (int i = 0; num[i]; ) {
		cnt++;
		i += (cnt >= 10 ? 2 : 1);
	}
	backtrack(0);
	return 0;
}