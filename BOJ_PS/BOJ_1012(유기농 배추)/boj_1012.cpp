#include <iostream>
#include <string.h>
#include <algorithm>
#define MAX 51

using namespace std;

int tc, n, m, k;
int map[MAX][MAX];
bool visit[MAX][MAX];
int dx[] = { 0,0,-1,1 };
int dy[] = { -1,1,0,0 };

void dfs(int x, int y) {
	for (int i = 0; i < 4; i++) {
		int nx = x + dx[i];
		int ny = y + dy[i];
		if (nx < 0 || ny < 0 || nx >= n || ny >= m)	continue;

		if (map[nx][ny] == 1 && !visit[nx][ny]) {
			visit[nx][ny] = 1;
			dfs(nx, ny);
		}
	}
}

int main() {
	ios_base::sync_with_stdio(false);	cin.tie(0);
	cin >> tc;
	while (tc--) {
		memset(map, 0, sizeof(map));
		memset(visit, 0, sizeof(visit));
		cin >> n >> m >> k;
		while (k--) {
			int x, y;
			cin >> x >> y;
			map[x][y] = 1;
		}

		int result = 0;
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < m; j++) {
				if (!visit[i][j] && map[i][j] == 1) {
					dfs(i, j);
					result++;
				}
			}
		}
		cout << result << endl;
	}

	return 0;
}
