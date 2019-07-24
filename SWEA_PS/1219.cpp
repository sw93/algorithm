#include <cstdio>
#include <cstring>
#define MAX 100
using namespace std;
int n, m;
bool isExisitRoad;
bool visit[MAX];
bool map[MAX][MAX];
void dfs(int s) {
	visit[s]=1;
	if(s==99) {
		isExisitRoad=1;
		return;
	}
	for (int x=0; x<MAX; x++) {
		if (map[s][x] && !visit[x])
			dfs(x);
	}
}
void solve() {
	for (int t=0; t<10; t++) {
		memset(map, 0, sizeof(map));
		memset(visit, 0, sizeof(visit));
		isExisitRoad=0;
		scanf("%d %d", &n, &m);
		int y, x;
		for (int i=0; i<m; i++) {
			scanf("%d %d", &y, &x);
			map[y][x]=1;
		}
		
		dfs(0);
		if (isExisitRoad) printf("#%d\n", n);
		else printf("#%d\n", n);
	}
}
int main() {
	solve();
	return 0;
}
