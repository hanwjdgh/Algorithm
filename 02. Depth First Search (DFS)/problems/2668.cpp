#include <iostream>
#include <ios>
#include <vector>
#include <algorithm>

#define MAX 101

using namespace std;

int visit[MAX], card[MAX];
int check[MAX];
vector <int > v;

void dfs(int cur) {
	int next = card[cur];

	visit[cur] = 1;

	if (!visit[next])
		dfs(next);
	else {
		if (!check[next]) {
			for (int pre = next; pre != cur; pre = card[pre]) 
				v.push_back(pre);
			v.push_back(cur);
		}
	}

	check[cur] = 1;
}

int main() {
	cin.tie(NULL);
	cout.tie(NULL);
	ios::sync_with_stdio(false);

	int N;

	cin >> N;

	for (int i = 0; i < N; i++)
		cin >> card[i + 1];

	for (int i = 1; i <= N; i++) {
		if (!visit[i])
			dfs(i);
	}

	sort(v.begin(), v.end());

	cout << v.size() << "\n";
	for (auto n : v)
		cout << n << "\n";

	return 0;
}