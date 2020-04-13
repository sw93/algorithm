#include <iostream>
#include <vector>
using namespace std;
const int MAX = 101;
const int dy[] = { 0, -1, 0, 1 };
const int dx[] = { 1, 0, -1, 0 };
int n, y, x, d, g;
int map[MAX][MAX];
int solve() {
	cin >> n;
	while (n--) {
		cin >> x >> y >> d >> g;
		vector<int> dir;
		dir.push_back(d);
		map[y][x] = 1;
		for (int i = 0; i < g; i++) {
			int dirSize = dir.size();
			for (int j = dirSize - 1; j >= 0; j--) {
				dir.push_back((dir[j] + 1) % 4);
			}
		}
		for (int i = 0; i < dir.size(); i++) {
			y += dy[dir[i]];
			x += dx[dir[i]];
			if (y < 0 || x < 0 || y >= MAX || x >= MAX) continue;
			map[y][x] = 1;
		}
	}
	int ret = 0;
	for (int r = 0; r < MAX - 1; r++) {
		for (int c = 0; c < MAX - 1; c++) {
			if (map[r][c] == 1 && map[r + 1][c] == 1 && map[r][c + 1] == 1 && map[r + 1][c + 1] == 1) {
				ret++;
			}
		}
	}
	return ret;
}
int main() {
	ios_base::sync_with_stdio(0); cin.tie(0);
	cout<<solve();
	return 0;
}