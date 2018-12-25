#include <iostream>
#include <cstdio>
#include <cstdlib>

using namespace std;

typedef struct {
	int cnt;
	int imp;
}node;
int rear = 0, front = 0;
node queue[1001];

void insertN(node key) {
	queue[rear].cnt = key.cnt;
	queue[rear].imp = key.imp;
	++rear;
}

node deleteN() {
	return queue[front++];
}

int main() {
	node *arr, tem;
	int N, M, cnum, cnt, chk = 1;
	int a, b, c;

	scanf("%d", &cnum);
	for (a = 0; a < cnum; a++) {
		rear = front = 0;
		chk = 1;
		scanf("%d %d", &N, &M);
		arr = (node *)calloc(N, sizeof(node));
		for (b = 0; b < N; b++) {
			arr[b].cnt = b;
			scanf("%d", &arr[b].imp);
			insertN(arr[b]);
		}

		while (front != rear) {
			for (b = front; b < rear; b++) {
				cnt = 0;
				for (c = b + 1; c < rear; c++) {
					if (queue[b].imp < queue[c].imp)
						++cnt;
				}
				if (cnt > 0)
					insertN(deleteN());
				else {
					tem = deleteN();
					if (M == tem.cnt) {
						printf("%d\n", chk);
						break;
					}
					++chk;
				}
			}
		}
	}
	return 0;
}