#include <iostream>
#include <ios>
#include <string>
#include <stack>

using namespace std;

int main() {
	cin.tie(NULL);
	cout.tie(NULL);
	ios::sync_with_stdio(false);

	for (int t_case = 1; t_case <= 10; t_case++) {
		stack <int> s;
		string str;
		int ans = 0, val = 1, N;

		cin >> N >> str;

		for (int i = 0; i < N; i++) {
			if (s.empty())
				s.push(str[i] - '0');
			else {
				if (s.top() == (str[i] - '0'))
					s.pop();
				else
					s.push(str[i] - '0');
			}
		}

		while (!s.empty()) {
			ans += s.top() * val;
			s.pop();

			val *= 10;
		}

		cout << "#" << t_case << " " << ans << "\n";
	}

	return 0;
}