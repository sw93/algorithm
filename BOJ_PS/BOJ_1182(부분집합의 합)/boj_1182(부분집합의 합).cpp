#include <iostream>
#include <algorithm>

using namespace std;

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	int n, s;
	int set[21];
	cin >> n >> s;
	for (int i = 0; i < n; i++) cin >> set[i];

	int sum = 0;
	int cnt = 0;
	for (int i = 1; i < (1 << n); i++) {	// 2^n 만큼 반복
		sum = 0;
		for (int j = 0; j < n; j++) {
			if (i&(1 << j))					
				sum += set[j];
		}
		if (sum == s)
			cnt++;
	}
	cout << cnt;

	return 0;
}