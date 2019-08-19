#include <iostream>
#include <cstring>
#include <algorithm>
#define MAX 8
#define endl "\n"
using namespace std;
int n, k, maxHeight, ans;
int map[MAX][MAX];
bool visit[MAX][MAX];
int dx[] = {1, -1, 0, 0};
int dy[] = {0, 0, -1, 1};

// 모의 SW 역량테스트 1949 등산로 조성 
// 가장 높은곳에서 시작
// 높은 지형 -> 낮은 지형 상/하/좌/우 이동 
// 최대 k만큼 지형을 깎는다. (오직 한 지점에만 가능) 

// y좌표, x좌표, 현재까지 길이, 공사 여부 
void dfs(int y, int x, int cnt, bool isCutting) {
	ans = max(ans, cnt);
	
	for (int i=0; i<4; i++) {
		int ny=y+dy[i];
		int nx=x+dx[i];
		
		// map범위를 초과하거나 이미 방문한 지점이면 continue 
		if (ny<0 || nx<0 || ny>=n || nx>=n || visit[ny][nx]) continue;
		
		// 내리막길 
		if (map[y][x] > map[ny][nx]) {
			visit[ny][nx]=1;
			dfs(ny, nx, cnt+1, isCutting);
			visit[ny][nx]=0;
		} 
		
		// 오르막길 && 공사진행 X 
		else if (map[y][x] <= map[ny][nx] && !isCutting) {
			
			// 최소한으로 높이를 깎는다. 
			for (int d=1; d<=k; d++) {
				isCutting=1;
				map[ny][nx] -= d;
				
				// 내리막길이 되면 
				if (map[y][x] > map[ny][nx]) {
					visit[ny][nx]=1;
					dfs(ny, nx, cnt+1, isCutting);
					visit[ny][nx]=0;
				}
				map[ny][nx] += d;
				isCutting=0;
			}	
		}
	}
}

void solve() {
	for (int y=0; y<n; y++) {
		for (int x=0; x<n; x++) {
			if (map[y][x] == maxHeight)	{
                visit[y][x]=1;
				dfs(y, x, 1, 0);
                visit[y][x]=0;
			}
		}
	}
}

void init() {
	int tc;
	cin>>tc;
	for (int t=1; t<=tc; t++) {
		cin>>n>>k;
		memset(map, 0, sizeof(map));
		memset(visit, 0, sizeof(visit));
		ans = 1;
		maxHeight = 0;
		
		for (int y=0; y<n; y++) {
			for (int x=0; x<n; x++) {
				cin>>map[y][x];
				maxHeight = max(maxHeight, map[y][x]);	
			}
		}
		
		solve();
		
		cout<<"#"<<t<<" "<<ans<<endl;	
	}
}

int main() {
	ios::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
	init();
	return 0;
}