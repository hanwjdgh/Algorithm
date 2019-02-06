#include <iostream>
#include <ios>

using namespace std;

int arr[50];

int main() {
	cin.tie(NULL);
	cout.tie(NULL);
	ios::sync_with_stdio(false);

	int T, K;
	
	cin >> T;

	for (int i = 1; i <= 45; i++)
		arr[i] = (i*(i + 1)) / 2;

	for (int i = 0; i < T; i++) {
		int chk = 0;
		cin >> K;
		
		for (int a = 1; a <= 45; a++) 
			for (int b = 1; b <= 45; b++) 
				for (int c = 1; c <= 45; c++) 
					if (arr[a] + arr[b] + arr[c] == K)
						chk = 1;

		if (chk)
			cout << "1" << "\n";
		else
			cout << "0" << "\n";

	}

	return 0;
}