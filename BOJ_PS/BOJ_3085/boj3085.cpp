#include <iostream>
#include <algorithm>
using namespace std;
int n;
char map[50][50];
void init() {
	cin >> n;
	for (int y = 0; y < n; y++) {
		for (int x = 0; x < n; x++) {
			cin >> map[y][x];
		}
	}
}
int eatCandy() {
	int ret = 1;

	// 열 체크
	for (int y = 0; y < n; y++) {
		int count = 1;
		for (int x = 1; x < n; x++) {
			if (map[y][x] == map[y][x - 1]) count++;
			else count = 1;
			ret = max(count, ret);
		}
	}

	// 행 체크
	for (int x = 0; x < n; x++) {
		int count = 1;
		for (int y = 1; y < n; y++) {
			if (map[y][x] == map[y - 1][x]) count++;
			else count = 1;
			ret = max(count, ret);
		}
	}

	return ret;
}
int main() {
	ios_base::sync_with_stdio(0); cin.tie(0);
	init();
	int ans = 0;
	for (int y = 0; y < n; y++) {
		for (int x = 0; x < n; x++) {

			// 오른쪽 탐색
			if (x + 1 < n) {
				swap(map[y][x], map[y][x + 1]);
				ans = max(ans, eatCandy());
				swap(map[y][x], map[y][x + 1]);
			}

			// 아래쪽 탐색
			if (y + 1 < n) {
				swap(map[y][x], map[y + 1][x]);
				ans = max(ans, eatCandy());
				swap(map[y][x], map[y + 1][x]);
			}
		}
	}
	cout << ans;
	return 0;
}