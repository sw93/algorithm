#include <vector>
#include <queue>
#include <algorithm>
using namespace std;
const int dy[] = { 0, -1, 0, 1 };
const int dx[] = { 1, 0, -1, 0 };
bool visit[100][100] = { 0, };
int bfs(int sy, int sx, int m, int n, vector<vector<int>> picture) {
    int color = picture[sy][sx];
    int size = 1;
    queue<pair<int, int> > q;
    q.push(make_pair(sy, sx));
    visit[sy][sx] = 1;
    
    while (!q.empty()) {
        int y = q.front().first;
        int x = q.front().second;
        q.pop();
        
        for (int i=0; i<4; i++) {
            int ny = y + dy[i];
            int nx = x + dx[i];
            if (ny<0 || nx<0 || ny>=m || nx>=n || visit[ny][nx] || picture[ny][nx] != color) continue;
            visit[ny][nx] = 1;
            q.push(make_pair(ny, nx));
            size++;
        }
    }
    return size;
}
// 전역 변수를 정의할 경우 함수 내에 초기화 코드를 꼭 작성해주세요.
vector<int> solution(int m, int n, vector<vector<int>> picture) {
    for (int y=0; y<m; y++) {
        for (int x=0; x<n; x++) {
            visit[y][x] = 0;
        }
    }
    int areaCount = 0;
    int maxAreaCount = 0;
    for (int y=0; y<m; y++) {
        for (int x=0; x<n; x++) {
            if (visit[y][x] || picture[y][x] == 0) continue;
            maxAreaCount = max(maxAreaCount, bfs(y, x, m, n, picture));
            areaCount++;
        }
    }
    vector<int> answer(2);
    answer[0] = areaCount;
    answer[1] = maxAreaCount;   
    return answer;
}