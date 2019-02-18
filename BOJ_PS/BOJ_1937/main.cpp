#include <iostream>
#include <algorithm>
#include <cstring>
#define MAX 500
using namespace std;
int n, ans;
int map[MAX][MAX], dp[MAX][MAX];
int dx[]={0,0,-1,1};
int dy[]={-1,1,0,0};
/**
 * 왜 정렬문제인지 모르겠다.
 * dp로 풀이 했으며 전체탐색으로는 시간초과가 난다.
 * dp[y][x]는 y에서 x로 올 수 있는 최대값이다.
 * 풀이 방법이 dp인 것만 알면 쉽게 풀 수 있었다.
 */
int dfs(int y, int x) {
    if(dp[y][x]!=-1) return dp[y][x];
    dp[y][x]=1;
    for(int i=0; i<4; i++) {
        int nx=x+dx[i];
        int ny=y+dy[i];
        if(nx<0 || nx>=n || ny<0 || ny>=n || map[y][x]>=map[ny][nx]) continue;
        dp[y][x]=max(dp[y][x], dfs(ny,nx)+1);
    }
    return dp[y][x];
}
int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    cin>>n;
    memset(dp, -1, sizeof(dp));
    for(int y=0; y<n; y++)
        for(int x=0; x<n; x++)
            cin>>map[y][x];
    for(int y=0; y<n; y++)
        for(int x=0; x<n; x++)
            ans=max(dfs(y,x), ans);
    cout<<ans;
    return 0;
}