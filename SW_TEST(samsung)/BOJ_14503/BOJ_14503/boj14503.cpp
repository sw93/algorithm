#include <iostream>
using namespace std;
int dy[] = { -1, 0, 1, 0 };
int dx[] = { 0, 1, 0, -1 };
int map[50][50];
int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    int n, m;
    cin >> n >> m;
    int y, x, dir;
    cin >> y >> x >> dir;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> map[i][j];
        }
    }

    int ans = 0;
    while (1) {

        // 현재구역 청소
        if (map[y][x] == 0) {
            map[y][x] = 2;
            ans++;
        }

        // 4방향 모두 청소가 되어 있는 경우
        if (map[y + 1][x] != 0 && map[y - 1][x] != 0 && map[y][x + 1] != 0 && map[y][x - 1] != 0) {
            y += dy[(dir + 2) % 4];
            x += dx[(dir + 2) % 4];

            // 뒤쪽 방향이 벽이라 후진할 수 없는 경우
            if (map[y][x] == 1) {
                break;
            }
            else {   // 한칸 후진
                continue;
            }
        }

        // 왼쪽방향 탐색
        dir = (dir + 3) % 4;

        // 왼쪽방향에 청소하지 않은 공간이 있는경우
        if (map[y + dy[dir]][x + dx[dir]] == 0) {
            y += dy[dir];
            x += dx[dir];
        }
        else {   // 왼쪽 재탐색
            continue;
        }
    }
    cout << ans << "\n";
    return 0;
}