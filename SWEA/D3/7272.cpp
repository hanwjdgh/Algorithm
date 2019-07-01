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
		string fstr, sstr;

		cin >> fstr >> sstr;

		cout << "#" << t_case << " ";

		if (fstr.length() != sstr.length())
			cout << "DIFF" << "\n";

		else {
			for (int i = 0; i < fstr.length(); i++) {
				if (fstr[i] == 'B')
					fstr[i] = '2';
				else if (fstr[i] == 'A' || fstr[i] == 'D' || fstr[i] == 'O' || fstr[i] == 'P' || fstr[i] == 'Q' || fstr[i] == 'R')
					fstr[i] = '1';
				else
					fstr[i] = '0';
			}

			for (int i = 0; i < fstr.length(); i++) {
				if (sstr[i] == 'B')
					sstr[i] = '2';
				else if (sstr[i] == 'A' || sstr[i] == 'D' || sstr[i] == 'O' || sstr[i] == 'P' || sstr[i] == 'Q' || sstr[i] == 'R')
					sstr[i] = '1';
				else
					sstr[i] = '0';
			}

			if (fstr == sstr)
				cout << "SAME" << "\n";
			else
				cout << "DIFF" << "\n";
		}
	}

	return 0;
}