#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <cstring>
using namespace std;
// 2020/04/12 14:55 문제풀이 시작
struct VIRUS {
    int y, x;
};
bool isAllSpread;
int n, m, ans=987654321;
int dy[] = {0, 0, 1, -1};
int dx[] = {1, -1, 0, 0};
int map[50][50];
vector<VIRUS> virus, selected;
void init() {
    cin>>n>>m;
    for (int y=0; y<n; y++) {
        for (int x=0; x<n; x++) {
            cin>>map[y][x];
            if (map[y][x] == 2) virus.push_back({y,x});
        }
    }
}
int spreadVirus() {
    isAllSpread = 1;
    queue<VIRUS> q;
    int timeMap[50][50];
    memset(timeMap, -1, sizeof(timeMap));

    for (int i=0; i<selected.size(); i++)  {
        q.push(selected[i]);
        timeMap[selected[i].y][selected[i].x] = 0;
    }

    while (!q.empty()) {
        int y = q.front().y;
        int x = q.front().x;
        q.pop();

        for (int i=0; i<4; i++) {
            int ny=y+dy[i];
            int nx=x+dx[i];

            // out of bound
            if (ny<0 || nx<0 || ny>=n || nx>=n) continue;

            // 벽 or 이미 바이러스 퍼진 경우
            if (map[ny][nx] == 1 || timeMap[ny][nx] != -1) continue;

            q.push({ny, nx});
            timeMap[ny][nx] = timeMap[y][x] + 1;
        }
    }

    int time=0;
    for (int y=0; y<n; y++) {
        for (int x=0; x<n; x++) {

            // 전부 전파하지 못한 경우
            if (map[y][x] == 0 && timeMap[y][x] == -1) {
                isAllSpread=0;
                return 987654321;
            }
                // 활성화 하지 않은 바이러스는 제외
            else if (map[y][x] == 0) {
                time = max(time, timeMap[y][x]);
            }
        }
    }
    return time;
}
void selectVirus(int index) {
    if (selected.size() == m) {
        int time = spreadVirus();
        if (isAllSpread) ans = min(ans, time);

        return;
    }

    for (int i=index; i<virus.size(); i++) {
        selected.push_back(virus[i]);
        selectVirus(i+1);
        selected.pop_back();
    }
}
int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    init();
    selectVirus(0);
    if (ans == 987654321) cout<<"-1"<<"\n";
    else cout<<ans<<"\n";
    return 0;
}