#include <cstdio>
#include <queue>
using namespace std;
int n, m;
const int dy[] = { -1, 0, 1, 0 };
const int dx[] = { 0, 1, 0, -1 };
int map[100][100];
int dist[100][100];
void bfs(int y, int x) {
	queue<pair<int, int> > q;
	q.push(make_pair(y, x));
	dist[y][x] = 1;

	while (!q.empty()) {
		y = q.front().first;
		x = q.front().second;
		q.pop();

		for (int i = 0; i < 4; i++) {
			int ny = y + dy[i];
			int nx = x + dx[i];
			if (ny < 0 || nx < 0 || ny >= n || nx >= m || dist[ny][nx] != 0 || map[ny][nx] != 1) continue;

			q.push(make_pair(ny, nx));
			dist[ny][nx] = dist[y][x] + 1;
		}
	}
}
int main() {
	scanf("%d %d", &n, &m);
	for (int y = 0; y < n; y++) {
		for (int x = 0; x < m; x++) {
			scanf("%1d", &map[y][x]);
		}
	}
	bfs(0, 0);
	printf("%d\n", dist[n - 1][m - 1]);
	return 0;
}