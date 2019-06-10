#include <iostream>
#include <ios>
#include <list>

using namespace std;

int main() {
	cin.tie(NULL);
	cout.tie(NULL);
	ios::sync_with_stdio(false);


	for (int t = 1; t <= 10; t++) {
		list <int > lst;
		int N, M, num;
		char ch;

		cin >> N;

		for (int i = 0; i < N; i++) {
			cin >> num;
			lst.push_back(num);
		}

		cin >> M;

		for (int i = 0; i < M; i++) {
			cin >> ch;
			int a, b;

			if (ch == 'I') {
				cin >> a >> b;
				list <int > temp;
				list<int>::iterator point = lst.begin();

				advance(point, a);

				for (int j = 0; j < b; j++) {
					cin >> num;
					temp.push_back(num);
				}

				lst.insert(point, temp.begin(), temp.end());
			}
			else if(ch=='D'){
				cin >> a >> b;
				list<int>::iterator point = lst.begin();
				
				advance(point, a);

				for (int j = 0; j < b; j++) 
					lst.erase(point++);
			}
			else {
				cin >> a;
				
				for (int j = 0; j < a; j++) {
					cin >> num;
					lst.push_back(num);
				}
			}
		}

		cout << "#" << t << " ";
		int cnt = 0;
		for (list<int>::iterator it = lst.begin(); it != lst.end(); it++) {
			cout << *it << " ";
			cnt++;
			if (cnt == 10)
				break;
		}
		cout << "\n";
	}

	return 0;
}