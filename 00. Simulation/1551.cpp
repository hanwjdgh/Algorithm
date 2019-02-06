#include <iostream>
#include <ios>
#include <vector>
#include <string>
#include <sstream>

using namespace std;

int main() {
	cin.tie(NULL);
	cout.tie(NULL);
	ios::sync_with_stdio(false);

	vector <int > v;
	int N, K, num;
	string arry;
	stringstream ss;

	cin >> N >> K >> arry;

	for (int i = 0; i < K; i++) {
		ss.str(arry);
		arry = "";
		while (ss >> num) {
			v.push_back(num);
			ss.ignore(1);
		}

		for (int j = 0; j < v.size() - 1; j++) {
			arry += to_string((v[j + 1] - v[j]));
			if (j == v.size() - 2)
				break;
			arry += ",";
		}
		ss.clear();
		v.clear();
	}

	cout << arry << "\n";

	return 0;
}