#include <iostream>
#include <ios>

#define MAX 1000001

using namespace std;

int visit[MAX], N;
int answer;

void newCalcAnswer(void) {
	int num = N;
	int pushCnt = 0;
	for (int i = N; i>1; i--) {    
		while (visit[i] > 0) {
			if (num%i == 0) {
				pushCnt += 1 + visit[i];    
				num /= i;
			}
			else
				break;
		}
		if (num == 1) {   
			answer = pushCnt;
			return;
		}
	}
	answer = -1;
}

void makeNums(int num, int pushCnt) { 
	if (pushCnt > 7)
		return;
	if (num > N)
		return;

	if (pushCnt > 0)
		visit[num] = pushCnt; 

	for (int i = 0; i<10; i++) {
		if (visit[i]) {
			makeNums(num * 10 + i, pushCnt + 1);
		}
	}
}


int main() {
	cin.tie(NULL);
	cout.tie(NULL);
	ios::sync_with_stdio(false);

	int T;

	cin >> T;

	for (int t_case = 1; t_case <= T; t_case++) {
		fill(visit, visit + MAX, 0);

		for (int i = 0; i < 10; i++)
			cin >> visit[i];
		cin >> N;

		if (N == 1 && visit[1])
			answer = 2;
		else {
			makeNums(0, 0);
			newCalcAnswer();
		}
		cout << "#" << t_case << " " << answer << "\n";
	}

	return 0;
}