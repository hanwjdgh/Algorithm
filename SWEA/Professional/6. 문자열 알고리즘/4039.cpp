#include <iostream>
#include <ios>
#include <string>
#include <algorithm>

#define MAX_L 200001

using namespace std;

int T, ans, L, pos, len;
int suffix_Array[MAX_L], LCP[MAX_L], Rank[MAX_L];
int group[MAX_L], team_group[MAX_L];
string S;

bool cmp(const int& A, const int& B) {
	if (group[A] == group[B])
		return group[A + pos] < group[B + pos];
	return group[A] < group[B];
}

void init() {
	ans = len = 0;
}

void make_Suffix() {
	pos = 1;

	for (int i = 0; i < L; i++) {
		suffix_Array[i] = i;
		group[i] = S[i] - 'a';
	}

	while (pos <= L) {
		group[L] = -1;

		sort(suffix_Array, suffix_Array + L, cmp);
		team_group[suffix_Array[0]] = 0;

		for (int i = 1; i < L; i++) {
			if (cmp(suffix_Array[i - 1], suffix_Array[i]))
				team_group[suffix_Array[i]] = team_group[suffix_Array[i - 1]] + 1;
			else
				team_group[suffix_Array[i]] = team_group[suffix_Array[i - 1]];
		}

		for (int i = 0; i < L; i++)
			group[i] = team_group[i];

		pos *= 2;
	}
}

int main() {
	cin.tie(NULL);
	cout.tie(NULL);
	ios::sync_with_stdio(false);

	cin >> T;

	for (int t_case = 1; t_case <= T; t_case++) {

		cin >> L >> S;

		init();

		make_Suffix();

		for (int i = 0; i < L; i++)
			Rank[suffix_Array[i]] = i;

		for (int i = 0; i < L; i++) {
			if (Rank[i]) {
				while (S[suffix_Array[Rank[i] - 1] + len] == S[i + len])
					len++;
				LCP[Rank[i]] = len;

				if (len)
					len--;
			}
		}
		
		for (int i = 1; i < L; i++)
			ans = max(ans, LCP[i]);

		cout << "#" << t_case << " " << ans << "\n";

	}
	return 0;
}