#include <iostream>

#define MAX 250001

using namespace std;

int visit[MAX];

int solution(vector<vector<int>> board, vector<int> nums) {
	int answer = 0, cnt = 0;

	for (int i = 0; i < nums.size(); i++)
		visit[nums[i]] = 1;

	for (int i = 0; i < board.size(); i++) {
		for (int j = 0; j < board[i].size(); j++) {
			if (visit[board[i][j]])
				board[i][j] = 0;
		}
	}

	for (int i = 0; i < board.size(); i++) {
		cnt = 0;
		for (int j = 0; j < board[i].size(); j++) {
			if (board[i][j] == 0)
				cnt++;
		}
		if (cnt == 4)
			answer++;

		cnt = 0;
		for (int j = 0; j < board[i].size(); j++) {
			if (board[j][i] == 0)
				cnt++;
		}
		if (cnt == 4)
			answer++;
	}

	cnt = 0;
	for (int i = 0; i < board.size(); i++) {
		if (board[i][i] == 0)
			cnt++;
	}
	if (cnt == 4)
		answer++;

	cnt = 0;
	for (int i = 0; i < board.size(); i++) {
		if (board[i][board.size()-i-1] == 0)
			cnt++;
	}
	if (cnt == 4)
		answer++;

	return answer;
}