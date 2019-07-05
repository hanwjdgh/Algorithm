#include <iostream>
#include <ios>
#include <stack>
#include <vector>
#include <string>

using namespace std;

int main() {
	cin.tie(NULL);
	cout.tie(NULL);
	ios::sync_with_stdio(false);

	for (int t = 1; t <= 10; t++) {
		int N, ans = 0;
		vector <char > v;
		stack <char > s;
		stack <int > st;
		string str;

		cin >> N >> str;

		for (int i = 0; i < N; i++) {
			if (str[i] >= '0' && str[i] <= '9')
				v.push_back(str[i]);
			else {
				if (s.empty())
					s.push(str[i]);
				else {
					if (str[i] == '+') {
						while (s.top() != '+') {
							v.push_back(s.top());
							s.pop();
							if (s.empty())
								break;
						}
						s.push(str[i]);
					}
					else
						s.push(str[i]);
				}
			}
		}
		

		while (!s.empty()) {
			v.push_back(s.top());
			s.pop();
		}


		for (auto n : v) {
			if (n >= '0'&&n <= '9')
				st.push(n - '0');
			else {
				int a = st.top();
				st.pop();
				int b = st.top();
				st.pop();
				if (n == '+')
					st.push(b + a);
				else
					st.push(b * a);
			}
		}

		cout << "#" << t << " " << st.top() << "\n";
	}

	return 0;
}