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

        // ���籸�� û��
        if (map[y][x] == 0) {
            map[y][x] = 2;
            ans++;
        }

        // 4���� ��� û�Ұ� �Ǿ� �ִ� ���
        if (map[y + 1][x] != 0 && map[y - 1][x] != 0 && map[y][x + 1] != 0 && map[y][x - 1] != 0) {
            y += dy[(dir + 2) % 4];
            x += dx[(dir + 2) % 4];

            // ���� ������ ���̶� ������ �� ���� ���
            if (map[y][x] == 1) {
                break;
            }
            else {   // ��ĭ ����
                continue;
            }
        }

        // ���ʹ��� Ž��
        dir = (dir + 3) % 4;

        // ���ʹ��⿡ û������ ���� ������ �ִ°��
        if (map[y + dy[dir]][x + dx[dir]] == 0) {
            y += dy[dir];
            x += dx[dir];
        }
        else {   // ���� ��Ž��
            continue;
        }
    }
    cout << ans << "\n";
    return 0;
}