#include <iostream>
#include <ios>
#include <list>

using namespace std;

int main() {
	cin.tie(NULL);
	cout.tie(NULL);
	ios::sync_with_stdio(false);

	list <int > lst;
	int N;

	cin >> N;

	for (int i = 1; i <= N; i++)
		lst.push_back(i);

	while (lst.size() > 1) {
		cout << lst.front() << " ";
		lst.pop_front();
		lst.push_back(lst.front());
		lst.pop_front();
	}

	cout << lst.front();
	
	return 0;
}