#include <iostream>
#include <ios>
#include <string>

using namespace std;

int T;

int main() {
	cin.tie(NULL);
	cout.tie(NULL);
	ios::sync_with_stdio(false);

	cin >> T;

	for (int t_case = 1; t_case <= T; t_case++) {
		string str1, str2, ans = "";
		int time1 = 0, time2 = 0, temp = 0;

		cin >> str1 >> str2;

		time1 = stoi(str1.substr(0, 2)) * 3600 + stoi(str1.substr(3, 2)) * 60 + stoi(str1.substr(6, 2));
		time2 = stoi(str2.substr(0, 2)) * 3600 + stoi(str2.substr(3, 2)) * 60 + stoi(str2.substr(6, 2));

		if (time2 > time1)
			temp = time2 - time1;
		else
			temp = (time2 + 86400) - time1;

		if ((temp / 3600) > 9)
			ans += to_string((temp / 3600)) + ":";
		else
			ans += ("0" + to_string((temp / 3600)) + ":");

		if (((temp % 3600) / 60) > 9)
			ans += to_string(((temp % 3600) / 60)) + ":";
		else
			ans += ("0" + to_string(((temp % 3600) / 60)) + ":");

		if (((temp % 3600) % 60) > 9)
			ans += to_string(((temp % 3600) % 60));
		else
			ans += ("0" + to_string(((temp % 3600) % 60)));

		cout << "#" << t_case << " " << ans << "\n";

	}

	return 0;
}