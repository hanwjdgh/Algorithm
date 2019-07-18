#include <iostream>
#include <ios>
#include <algorithm>
#include <string>

using namespace std;

int T, ans;
string f_str, s_str;
long long f_arr[41], s_arr[121];
long long f_tmp, s_tmp;

int main() {
	cin.tie(NULL);
	cout.tie(NULL);
	ios::sync_with_stdio(false);

	cin >> T;

	for (int t_case = 1; t_case <= T; t_case++) {
		int cnt = 0;
		ans = 0;
		f_tmp = s_tmp = 0;

		cin >> f_str >> s_str;

		for (int i = 0; i < f_str.length(); i++)
			f_tmp += (f_str[i] - '0')*pow(2, f_str.length() - i - 1);

		for (int i = 0; i < s_str.length(); i++)
			s_tmp += (s_str[i] - '0')*pow(3, s_str.length() - i - 1);

		for (int i = 0; i < f_str.length(); i++) {
			if (f_str[i] == '0')
				f_arr[i] = f_tmp + pow(2, f_str.length() - i - 1);
			else
				f_arr[i] = f_tmp - pow(2, f_str.length() - i - 1);
		}

		for (int i = 0; i < s_str.length(); i++) {
			long long temp = s_tmp - (s_str[i] - '0')*pow(3, s_str.length() - i - 1);

			for (int j = 0; j < 3; j++) {
				if (j == s_str[i] - '0')
					continue;
				s_arr[cnt++] = temp + j*pow(3, s_str.length() - i - 1);
			}
		}

		for (int i = 0; i < f_str.length(); i++) {
			for(int j=0; j<cnt; j++)
				if (f_arr[i] == s_arr[j]) {
					ans = f_arr[i];
					break;
				}
		}

		cout << "#" << t_case << " " << ans << "\n";
	}

	return 0;
}