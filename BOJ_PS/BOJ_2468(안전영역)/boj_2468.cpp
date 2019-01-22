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
* ��� ���̿� ���� ����� �ʴ� ���������� ������ ī��Ʈ ���ָ� �Ǵ� ����
* dfs / bfs�� Ǯ���� �� �ִ�. Ư�� 0�� ������� �ʾҴµ� �Ʒ� ��Ʈ�� ����
* �� ���� �ʴ� ��쵵 �ִٰ� �����־���.... ������ �����غ��� ���� ���̰� 1��
* ��찡 ���� �� �ֱ� ������ 0�� ����� �ؾ��մϴ�.
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