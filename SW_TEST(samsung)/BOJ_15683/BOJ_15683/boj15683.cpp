#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
struct CCTV {
	int type, y, x;
};
int n, m, ans = 987654321;
const int rotateCount[] = { 4,2,4,4,1 };
int map[8][8];
vector<CCTV> cctv;
void init() {
	cin >> n >> m;
	for (int y = 0; y < n; y++) {
		for (int x = 0; x < m; x++) {
			cin >> map[y][x];
			if (map[y][x] != 0 && map[y][x] != 6) {
				cctv.push_back({ map[y][x], y, x });
			}
		}
	}
}
void copyMap(int src[8][8], int desc[8][8]) {
	for (int y = 0; y < n; y++) {
		for (int x = 0; x < m; x++) {
			desc[y][x] = src[y][x];
		}
	}
}
void rotateCamera(int dir, CCTV cctv) {
	dir %= 4;

	if (dir == 0) {
		for (int x = cctv.x + 1; x < m; x++) {
			if (map[cctv.y][x] == 6) break;
			map[cctv.y][x] = -1;
		}
	} else if (dir == 1) {
		for (int y = cctv.y - 1; y >= 0; y--) {
			if (map[y][cctv.x] == 6) break;
			map[y][cctv.x] = -1;
		}
	} else if (dir == 2) {
		for (int x = cctv.x - 1; x >= 0; x--) {
			if (map[cctv.y][x] == 6) break;
			map[cctv.y][x] = -1;
		}
	} else if (dir == 3) {
		for (int y = cctv.y + 1; y < n; y++) {
			if (map[y][cctv.x] == 6) break;
			map[y][cctv.x] = -1;
		}
	}
}
void dfs(int index) {
	if (index == cctv.size()) {
		int safeArea = 0;
		for (int y = 0; y < n; y++) {
			for (int x = 0; x < m; x++) {
				if (map[y][x] == 0) safeArea++;
			}
		}
		ans = min(ans, safeArea);
		return;
	}
	int type = cctv[index].type;
	int backup[8][8] = { 0, };
	for (int i = 0; i < rotateCount[type-1]; i++) {
		copyMap(map, backup);
		if (type == 1) {
			rotateCamera(i, cctv[index]);
		} else if (type == 2) {
			rotateCamera(i, cctv[index]);
			rotateCamera(i + 2, cctv[index]);
		} else if (type == 3) {
			rotateCamera(i, cctv[index]);
			rotateCamera(i + 1, cctv[index]);
		} else if (type == 4) {
			rotateCamera(i, cctv[index]);
			rotateCamera(i + 1, cctv[index]);
			rotateCamera(i + 2, cctv[index]);
		} else if (type == 5) {
			rotateCamera(i, cctv[index]);
			rotateCamera(i + 1, cctv[index]);
			rotateCamera(i + 2, cctv[index]);
			rotateCamera(i + 3, cctv[index]);
		}
		dfs(index + 1);
		copyMap(backup, map);
	}

}
int main() {
	ios_base::sync_with_stdio(0); cin.tie(0);
	init();
	dfs(0);
	cout << ans << "\n";
	return 0;
}