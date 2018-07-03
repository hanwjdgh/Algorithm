#include <iostream>
#include <cstdio>
#include <algorithm>
#include <vector>

using namespace std;

vector<int> histo;

int area(int s, int f) {
	if (s > f)
		return 0;
	if (s == f)
		return histo[s];

	int mid = (s + f) / 2;
	int size = max(area(s, mid - 1), area(mid + 1, f));
	int l = mid, r = mid, h = histo[mid];

	while (1) {
		size = max(size, (r - l + 1)*h);
		if (l == s && r == f)
			break;
		int Lh = l>s ? min(h, histo[l - 1]) : -1;
		int Rh = r < f ? min(h, histo[r + 1]) : -1;
		if (l == s) {
			r++;
			h = Rh;
		}
		else if (r == f) {
			l--;
			h = Lh;
		}
		else if (Rh > Lh) {
			r++;
			h = Rh;
		}
		else {
			l--;
			h = Lh;
		}
	}
	return size;
}

int main() {
	int N, num;
	scanf("%d", &N);
	for (int i = 0; i < N; i++) {
		scanf("%d", &num);
		histo.push_back(num);
	}
	printf("%d\n", area(0, histo.size() - 1));
}