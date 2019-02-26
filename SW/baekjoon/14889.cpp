#include <iostream>
#include <ios>
#include <algorithm>
#include <vector>

using namespace std;

vector <int > t1, t2;
int N, visit[21];
int ab[21][21];
int min_v = 1e9;

void find(int cnt) {
	if(cnt>=N){
		if (t1.size() == t2.size()) {
			int sum_t1 = 0, sum_t2 = 0;

			for (int i = 0; i < t1.size(); i++) 
				for (int j = i+1; j < t1.size(); j++) 
					sum_t1 += (ab[t1[i]][t1[j]]+ ab[t1[j]][t1[i]]);
			

			for (int i = 0; i < t2.size(); i++) 
				for (int j = i+1; j < t2.size(); j++) 
					sum_t2 += (ab[t2[i]][t2[j]]+ ab[t2[j]][t2[i]]);

			min_v = min(min_v, abs(sum_t1 - sum_t2));
		}
		return;
	}

	t1.push_back(cnt);
	find(cnt + 1);
	t1.pop_back();

	t2.push_back(cnt);
	find(cnt + 1);
	t2.pop_back();
}

int main() {
	cin.tie(NULL);
	cout.tie(NULL);
	ios::sync_with_stdio(false);

	cin >> N;

	for (int i = 0; i < N; i++)
		for (int j = 0; j < N; j++)
			cin >> ab[i][j];

	find(0);

	cout << min_v << "\n";

	return 0;
}