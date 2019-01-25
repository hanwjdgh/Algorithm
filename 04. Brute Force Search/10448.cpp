#include <iostream>
#include <cstdio>
#include <vector>

using namespace std;

vector<int > v, tri;

int main() {
	int K,num;
	scanf("%d", &K);
	for (int i = 0; i < K; i++) {
		scanf("%d", &num);
		v.push_back(num);
	}
	for (int i = 1; i <= 1000; i++) 
		if((i*(i + 1)) / 2 <=1000)
			tri.push_back((i*(i+1))/2);

	for (int a = 0; a < K; a++) {
		int cnt = 0;
		for (int i = 0; i < tri.size(); i++) {
			for (int j = 0; j < tri.size(); j++) {
				for (int k = 0; k < tri.size(); k++) {
					if (v[a] == (tri[i] + tri[j] + tri[k])) 
						cnt = 1;
				}
			}
		}
		if (cnt == 1)
			printf("1\n");
		else
			printf("0\n");
	}
	return 0;
}