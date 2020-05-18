#include <iostream>
#include <cstring>
#include <queue>
using namespace std;
int w, h;
const int dy[] = { -1, -1, 0, 1, 1, 1, 0, -1 };
const int dx[] = { 0, 1, 1, 1, 0, -1, -1, -1 };
int map[50][50];
bool visit[50][50];
void bfs(int y, int x) {
	queue<pair<int, int> > q;
	q.push(make_pair(y, x));
	visit[y][x] = 1;

	while (!q.empty()) {
		y = q.front().first;
		x = q.front().second;
		q.pop();

		for (int i = 0; i < 8; i++) {
			int ny = y + dy[i];
			int nx = x + dx[i];
			if (ny < 0 || nx < 0 || ny >= h || nx >= w || visit[ny][nx]) continue;
			if (map[ny][nx] == 1) {
				q.push(make_pair(ny, nx));
				visit[ny][nx] = 1;
			}
		}
	}
}
int main() {
	ios_base::sync_with_stdio(0); cin.tie(0);
	while (1) {
		cin >> w >> h;
		if (w == 0 && h == 0) break;
		memset(map, 0, sizeof(map));
		memset(visit, 0, sizeof(visit));
		for (int y = 0; y < h; y++) {
			for (int x = 0; x < w; x++) {
				cin >> map[y][x];
			}
		}

		int landCount = 0;
		for (int y = 0; y < h; y++) {
			for (int x = 0; x < w; x++) {
				if (map[y][x] == 1 && visit[y][x] == 0) {
					bfs(y, x);
					landCount++;
				}
			}
		}
		cout << landCount << "\n";
	}
	return 0;
}