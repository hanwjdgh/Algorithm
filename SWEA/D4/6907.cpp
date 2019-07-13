#include <iostream>
#include <ios>
#include <string>
#include <vector>

using namespace std;

int T, ans;

string prefix[21] = { "yotta", "zetta", "exa", "peta", "tera",
"giga", "mega", "kilo", "hecto", "deca", "deci", "centi", "milli", "micro", "nano",
"pico", "femto", "ato", "zepto", "yocto" };

int indic[21] = { 24, 21, 18, 15, 12, 9, 6, 3, 2, 1, -1, -2, -3, -6, -9, -12, -15, -18, -21, -24 };

int main() {
	cin.tie(NULL);
	cout.tie(NULL);
	ios::sync_with_stdio(false);

	cin >> T;

	for (int t_case = 1; t_case <= T; t_case++) {
		ans = 0;
		vector <int > v;
		string num, pre, unit;
		int idx = 0, tmp = 0;
		bool flag = false;

		cin >> num >> pre;

		for (int i = 0; i < 21; i++) {
			if (pre == prefix[i]) {
				idx = i;
				flag = true;
			}
		}

		if (flag) {
			tmp = indic[idx];
			cin >> unit;
		}

		if (num[1] != '.') {
			bool flag = false;
			for (int i = 0; i < num.size(); i++) {
				if (num[i] == '.') {
					flag = true;
					continue;
				}
				if (flag == false)
					tmp++;
				v.push_back(num[i] - '0');
			}
			tmp--;
		}

		else {
			if (num[0] == '0') {
				bool flag = false;
				for (int i = 2; i < num.size(); i++) {
					if (flag == false)
						tmp--;
					if (num[i] >= '1' && num[i] <= '9')
						flag = true;
					if (flag == true)
						v.push_back(num[i] - '0');
				}
			}
			else {
				for (int i = 0; i < num.size(); i++) {
					if (num[i] == '.')
						continue;
					v.push_back(num[i] - '0');
				}
				tmp--;
			}
		}

		cout << "#" << t_case << " " << v[0];

		if (v.size() == 1) {
			cout << " * " << "10^" << tmp << " ";

			if (flag)
				cout << unit << "\n";
			else
				cout << pre << "\n";
		}
		else {
			cout << ".";
			for (int i = 1; i < v.size(); i++)
				cout << v[i];
			cout << " * " << "10^" << tmp << " ";
			if (flag)
				cout << unit << "\n";
			else
				cout << pre << "\n";
		}

	}

	return 0;
}