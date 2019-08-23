#include <iostream>
#include <cstring>
#include <queue>
using namespace std;
int n, m, r, c, l;
int dy[] = {-1, 1, 0, 0};
int dx[] = {0, 0, -1, 1};
int map[50][50];
bool visit[50][50];
struct node {
	int y, x, time;
	node(int _y, int _x, int _time) {
		y = _y;
		x = _x;
		time = _time;
	}
};
void init() {
	memset(map, 0, sizeof(map));
	memset(visit, 0, sizeof(visit));

	cin>>n>>m>>r>>c>>l;
	for (int y=0; y<n; y++) 
		for (int x=0; x<m; x++)
			cin>>map[y][x];
}
void bfs() {
	queue<node> q;
	q.push(node(r, c, 1));
	visit[r][c]=1;
	
	while (!q.empty()) {
		int y = q.front().y;
		int x = q.front().x;
		int elapsedTime = q.front().time;
		int curPipeType = map[y][x];
		q.pop();
		
		if (elapsedTime == l) continue;
		
		for (int i=0; i<4; i++) {
			int ny = y + dy[i];
			int nx = x + dx[i];
			int nextPipeType = map[ny][nx];
			
			if (ny<0 || nx<0 || ny>=n || nx>=m || nextPipeType == 0 || visit[ny][nx]) continue;
			/*******************************************************
			        			 dx, dy 조건         
			        i=0 -> 상 / i=1 -> 하 / i=2 -> 좌 / i=3 -> 우
			        
			                     PipeType 조건
			   1 -> 상/하/좌/우
			   2 -> 상/하
			   3 -> 좌/우
			   4 -> 상/우
			   5 -> 하/우
			   6 -> 하/좌
			   7 -> 상/좌
			*******************************************************/ 
			if (curPipeType == 2 && (i == 2 || i == 3)) continue;
			else if (curPipeType == 3 && (i == 0 || i == 1)) continue;
			else if (curPipeType == 4 && (i == 1 || i == 2)) continue;
			else if (curPipeType == 5 && (i == 0 || i == 2)) continue;
			else if (curPipeType == 6 && (i == 0 || i == 3)) continue;
			else if (curPipeType == 7 && (i == 1 || i == 3)) continue;
			
			// 여기서 반대가 되어야함
			// 즉 현재위치에서 왼쪽으로 간다면 다음 파이프는 오른쪽이 뚫려있어야 통과 가능 
			if (i == 0) {
				if (nextPipeType == 1 || nextPipeType == 2 || nextPipeType == 5 || nextPipeType == 6) {
					visit[ny][nx]=1;
					q.push(node(ny, nx, elapsedTime+1));
				}
			} else if (i == 1) {
				if (nextPipeType == 1 || nextPipeType == 2 || nextPipeType == 4 || nextPipeType == 7) {
					visit[ny][nx]=1;
					q.push(node(ny, nx, elapsedTime+1));
				}
			} else if (i == 2) {
				if (nextPipeType == 1 || nextPipeType == 3 || nextPipeType == 4 || nextPipeType == 5) {
					visit[ny][nx]=1;
					q.push(node(ny, nx, elapsedTime+1));
				}
			} else {
				if (nextPipeType == 1 || nextPipeType == 3 || nextPipeType == 6 || nextPipeType == 7) {
					visit[ny][nx]=1;
					q.push(node(ny, nx, elapsedTime+1));
				}
			}
		}
	}
}
int getAnswer() {
	int ans=0;
	for (int y=0; y<n; y++)
		for (int x=0; x<m; x++)
			if (visit[y][x]) ans++;
			
	return ans;	
}
int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	int tc;
	cin>>tc;
	for (int t=1; t<=tc; t++) {
		init();
		bfs();
		
		cout<<"#"<<t<<" "<<getAnswer()<<"\n";	
	}
	return 0;	
}