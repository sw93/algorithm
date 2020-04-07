#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>
using namespace std;
struct VIRUS {
	int vy, vx;
};
int n, m, ans;
int dy[] = { -1,0,1,0 };
int dx[] = { 0,1,0,-1 };
int map[8][8];
vector<VIRUS> virus;

void init() {
	cin >> n >> m;
	for (int y = 0; y < n; y++) {
		for (int x = 0; x < m; x++) {
			cin >> map[y][x];
			if (map[y][x] == 2) {
				virus.push_back({ y,x });
			}
		}
	}
}

// 모든경우에 대해 진행하기 때문에 map원본 필요
void copyMap(int (*src)[8], int (*dest)[8]) {
	for (int y = 0; y < n; y++) {
		for (int x = 0; x < m; x++) {
			dest[y][x] = src[y][x];
		}
	}
}

// 바이러스 퍼뜨리기
void bfs() {
	int map2[8][8];
	copyMap(map, map2);
	queue<VIRUS> q;
	for (int i = 0; i < virus.size(); i++) q.push(virus[i]);

	while (!q.empty()) {
		int y = q.front().vy;
		int x = q.front().vx;
		q.pop();

		for (int i = 0; i < 4; i++) {
			int ny = y + dy[i];
			int nx = x + dx[i];

			if (ny < 0 || nx < 0 || ny >= n || nx >= m) continue;
			
			if (map2[ny][nx] == 0) {
				map2[ny][nx] = 2;
				q.push({ ny,nx });
			}
		}
	}

	int safeArea = 0;
	for (int y = 0; y < n; y++) {
		for (int x = 0; x < m; x++) {
			if (map2[y][x] == 0) {
				safeArea++;
			}
		}
	}
	ans = max(ans, safeArea);
}

// 기둥 세우기
void dfs(int sy, int count) {
	if (count == 3) {
		bfs();
		return;
	}

	for (int y = sy; y < n; y++) {
		for (int x = 0; x < m; x++) {
			// 기둥은 안전지대에만 세울 수 있음
			if (map[y][x] != 0) continue;
			map[y][x] = 1;
			dfs(y, count + 1);
			map[y][x] = 0;
		}
	}
}
int main() {
	ios_base::sync_with_stdio(0); cin.tie(0);
	init();
	dfs(0, 0);
	cout << ans;
	return 0;
}