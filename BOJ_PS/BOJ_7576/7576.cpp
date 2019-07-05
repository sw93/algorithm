#include <stdio.h>
#include <queue>
#define MAX 1000
using namespace std;
struct tomatoInfo {
	int cy, cx, time;
};
int n, m;
const int dx[] = {0, 0, -1, 1};
const int dy[] = {1, -1, 0, 0};
int map[MAX][MAX];
bool visit[MAX][MAX];
queue<tomatoInfo> q;

void init() {
	scanf("%d %d", &n, &m);
	for (int y=0; y<m; y++) {
		for (int x=0; x<n; x++) {
			scanf("%d", &map[y][x]);
			if (map[y][x] == 1) {
				q.push({y, x, 0});
				visit[y][x]=1;
			}
		}
	}
}

bool isOutOfBoundMap(int y, int x) {
	if (x<0 || y<0 || x>=n || y>=m) {
		return true;
	}
	return false;
}

bool checkMap() {
	for (int y=0; y<m; y++) {
		for (int x=0; x<n; x++) {
			if (map[y][x]==0) {
				return false;
			}
		}
	}
	return true;
}

void bfs() {
	int t;
	while (!q.empty()) {
		int y = q.front().cy;
		int x = q.front().cx;	
		t = q.front().time;
		q.pop();
		
		for (int i=0; i<4; i++) {
			int ny = y + dy[i];
			int nx = x + dx[i];
			
			if (isOutOfBoundMap(ny, nx) || visit[ny][nx]) {
				continue;
			}
			if (map[ny][nx] == 0 && !visit[ny][nx]) {
				q.push({ny, nx, t+1});
				map[ny][nx]=1;
				visit[ny][nx]=1;
			}
		}
	}
	
	checkMap()==1 ? printf("%d", t) : printf("-1");	
}
int main() {
	init();
	bfs();
	return 0;
}
