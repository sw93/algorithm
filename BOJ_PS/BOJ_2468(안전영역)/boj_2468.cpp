#include <cstring>
#include <iostream>
#include <algorithm>
#define MAX 100
using namespace std;
int n,result;
int map[MAX][MAX];
bool visit[MAX][MAX];
int dx[] = { -1,1,0,0 };
int dy[] = { 0,0,-1,1 };
/*
* 모든 높이에 대해 잠기지 않는 안전영역의 갯수를 카운트 해주면 되는 문제
* dfs / bfs로 풀이할 수 있다. 특히 0은 고려하지 않았는데 아래 노트를 보니
* 비가 오지 않는 경우도 있다고 써져있었다.... 하지만 생각해보면 전부 높이가 1인
* 경우가 있을 수 있기 때문에 0도 고려를 해야합니다.
*/
void dfs(int x, int y, int height) {
	visit[x][y] = 1;

	for (int i = 0; i < 4; i++) {
		int nx = x + dx[i];
		int ny = y + dy[i];
		if (nx < 0 || ny < 0 || nx >= n || ny >= n)	continue;
		if (map[nx][ny] > height && !visit[nx][ny])	dfs(nx, ny, height);
	}
}
int main() {
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	cin >> n;
	int maxDepth = 0;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cin >> map[i][j];
			maxDepth = max(maxDepth, map[i][j]);
		}
	}
	for (int height = 0; height <= maxDepth; height++) {
		int safeBlock = 0;
		memset(visit, 0, sizeof(visit));
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				if (map[i][j] > height && !visit[i][j]) {
					dfs(i, j, height);
					safeBlock++;
				}
			}
		}
		result = max(result, safeBlock);
	}
	cout << result << endl;
}