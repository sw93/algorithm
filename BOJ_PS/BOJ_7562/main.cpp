#include <iostream>
#include <vector>
#include <queue>
using namespace std;
int n,destx, desty;
int dx[]={-2,-2,-1,-1,1,1,2,2};
int dy[]={-1,1,-2,2,-2,2,-1,1};
vector<vector<int> > map;
/**
 * 문제가 몇번만에 이동할 수 있는지 알아내는 문제입니다. 즉, 최소값을 구하는 문제이므로 bfs를 사용했습니다.
 * visit배열을 쓰는 대신 map을 -1로 재선언 해주어 방문을 하면 0을 넣어줬습니다.
 * visit배열을 사용한다면 bool visit[MAX][MAX]를 선언한뒤 조건에 추가해주면 됩니다.
 * 좌표가 out of bound이면 탐색을 하지 않고 방문을 하지 않은 상태 즉 map[x][y]==-1이라면
 * bfs로 다시 방문을 해주면서 카운트하면 되는 문제입니다.
 */
void bfs(int x, int y) {
    queue<pair<int, int> > q;
    q.push(make_pair(x,y));
    map[x][y]=0;
    while(!q.empty()) {
        x=q.front().first;
        y=q.front().second;
        q.pop();
        for(int i=0; i<8; i++) {
            int nx=x+dx[i];
            int ny=y+dy[i];
            if(nx<0 || ny<0 || nx>=n || ny>=n)  continue;
            if(map[nx][ny]==-1) {
                q.push(make_pair(nx, ny));
                map[nx][ny]=map[x][y]+1;
                if(nx==destx && ny==desty)  return;
            }
        }
    }
}
int main() {
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    int tc;
    cin>>tc;
    for(int i=0; i<tc; i++) {
        int x,y;
        cin>>n;
        cin>>x>>y>>destx>>desty;
        map=vector<vector<int> >(n, vector<int>(n,-1));
        bfs(x,y);
        cout<<map[destx][desty]<<endl;
    }
    return 0;
}