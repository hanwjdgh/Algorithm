#include <iostream>
#include <ios>
#include <string>
#include <algorithm>

using namespace std;

bool flag;
string str[4] = { "00","01","10","11" };
int T, A, B, C, D, sum;

void dfs(int cnt, string tmp) {
	if (flag)
		return;

	if (A < 0 || B < 0 || C < 0 || D < 0)
		return;

	if (abs(B - C) > 1)
		return;

	if (cnt == sum) {
		cout << tmp << "\n";
		flag = true;
		return;
	}

	int len = tmp.length();

	if (tmp[len - 1] == '0') {
		A--;
		dfs(cnt + 1, tmp + "0");
		A++;

		B--;
		dfs(cnt + 1, tmp + "1");
		B++;

		return;
	}

	C--;
	dfs(cnt + 1, tmp + "0");
	C++;

	D--;
	dfs(cnt + 1, tmp + "1");
	D++;
}

int main() {
	cin.tie(NULL);
	cout.tie(NULL);
	ios::sync_with_stdio(false);

	cin >> T;

	for (int t_case = 1; t_case <= T; t_case++) {

		sum = 0;
		flag = false;

		cin >> A >> B >> C >> D;

		sum = A + B + C + D;

		cout << "#" << t_case << " ";

		dfs(0, "0");
		dfs(0, "1");

		if (!flag)
			cout << "impossible" << "\n";
	}

	return 0;
}