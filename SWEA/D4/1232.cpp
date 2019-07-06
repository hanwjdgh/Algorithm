#include <iostream>
#include <ios>
#include <string>
#include <stack>
#include <vector>

using namespace std;

vector <vector <int > > v;
double tree[1001];
char cal[1001];
stack <double > s;
int N;

void postorder(int cur) {
	for (int i = 0; i < v[cur].size(); i++) {
		postorder(v[cur][i]);
	}
	
	if (cal[cur] == '+' || cal[cur] == '-' || cal[cur] == '*' || cal[cur] == '/') {
		double b = s.top();
		s.pop();
		double a = s.top();
		s.pop();

		switch (cal[cur]) {
		case '+':
			s.push(a + b);
			break;
		case '-':
			s.push(a - b);
			break;
		case '*':
			s.push(a * b);
			break;
		case '/':
			s.push(a / b);
			break;
		default:
			break;
		}
	}
	else
		s.push(tree[cur]);
}


int main() {
	cin.tie(NULL);
	cout.tie(NULL);
	ios::sync_with_stdio(false);

	for (int t = 1; t <= 10; t++) {
		cin >> N;

		v.clear();
		v.resize(N + 1);

		stack <double >temp;

		fill(cal, cal + 1001, '0');
		fill(tree, tree + 1001, 0.0);
		swap(temp, s);

		for (int i = 1; i <= N; i++) {
			int a, b, c;
			string str;

			cin >> a >> str;

			if (str == "+" || str == "-" || str == "*" || str == "/") {
				cin >> b >> c;
				cal[i] = str[0];
				v[a].push_back(b);
				v[a].push_back(c);
			}
			else
				tree[i] = stod(str);

		}

		postorder(1);

		cout << "#" << t << " " << (int)s.top() << "\n";
	}

	return 0;
}