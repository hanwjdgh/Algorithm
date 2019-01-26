#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int solution(int l, vector<int> v) {
    int answer = 0;

	sort(v.begin(), v.end());

	int L = 1, R = l;

	while (L <= R) {
		int mid = (L + R) / 2;
		int cnt = 0, max_v = 0, min_v = 0;
		
		for (int i = 0; i < v.size(); i++) {
			if (i == 0) {
				if (v[i] - mid > 0)
					cnt++;
				if (v.size() == 1) {
					if (v[i] + mid < l)
						cnt++;
				}
			}
			else if (i == v.size() - 1) {
				if (v[i] + mid < l)
					cnt++;
			}
			else {
				if (v[i] - mid > max_v)
					cnt++;
			}
			min_v = v[i] - mid;
			max_v = v[i] + mid;
		}
		

		if (cnt < 1)
			R = mid - 1;
		else
			L = mid + 1;
	}

	answer = L;

	return answer;
}