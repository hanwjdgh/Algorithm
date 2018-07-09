#include <iostream>
#include <cstdio>

using namespace std;

int n, arr[20], visit[20];

void find(int cur, int cnt) {  
	if (cur == n && cnt == 6) {
		for (int i = 0; i < n; i++) { 
			if (visit[i] == 1) 
				printf("%d ", arr[i]);
		}
		printf("\n");
	}
	if (cur == n) 
		return;
	visit[cur] = 1;
	find(cur + 1, cnt + 1);
	visit[cur] = 0;  
	find(cur + 1, cnt);
}

int main() {
	while (1) {
		scanf("%d", &n);
		if (n == 0)
			break;
		else {
			for (int i = 0; i < n; i++) 
				scanf("%d",&arr[i]);
			visit[20] = { 0, }; 
			find(0, 0);
		}
		printf("\n");
	}
	return 0;
}
