#include <iostream>
#include <queue>
using namespace std;
struct SHARK {
	int y, x, time;
};
SHARK shark;
int n, sharkSize, eatCount;
const int dy[] = { -1, 1, 0, 0 };
const int dx[] = { 0, 0, -1, 1 };
int map[20][20];
void init() {
	cin >> n;
	for (int y = 0; y < n; y++) {
		for (int x = 0; x < n; x++) {
			cin >> map[y][x];
			if (map[y][x] == 9) {
				shark.y = y, shark.x = x, shark.time = 0;
				sharkSize = 2, eatCount = 0;
				map[y][x] = 0;
			}
		}
	}
}
void bfs() {
	bool existFood = 1;
	while (existFood) {
		existFood = 0;
		bool visit[20][20] = { 0 };
		queue<SHARK> q;
		q.push(shark);
		visit[shark.y][shark.x] = 1;

		SHARK nextFood;	// ���� ���� ����
		nextFood.y = 20;
		nextFood.time = -1;
		while (!q.empty()) {

			// Ž�� ���� ��ġ
			SHARK cur = q.front();
			q.pop();

			// ���� ������ ��ġ�� ã�� ��� Ž�� �ߴ�
			if (nextFood.time != -1 && cur.time > nextFood.time) break;

			// ���̸� ã�����
			if (map[cur.y][cur.x] != 0 && map[cur.y][cur.x] < sharkSize) {
				existFood = 1;

				// ���� ã�� ������ ��ǥ�� �����̰ų� ���ʿ� �ִ°��
				if (cur.y < nextFood.y || (cur.y == nextFood.y && cur.x < nextFood.x)) {
					nextFood = cur;
				}
			}

			// 4���� Ž��
			for (int i = 0; i < 4; i++) {
				int ny = cur.y + dy[i];
				int nx = cur.x + dx[i];
				int time = cur.time + 1;
				if (ny < 0 || nx < 0 || ny >= n || nx >= n || visit[ny][nx]) continue;
				if (map[ny][nx] > sharkSize) continue;
				visit[ny][nx] = 1;
				q.push({ ny,nx, time });
			}
		}

		// Ž�� ������ ���̸� ã�����
		if (existFood) {
			eatCount++;
			shark = nextFood;
			if (sharkSize == eatCount) {
				sharkSize++;
				eatCount = 0;
			}
			map[shark.y][shark.x] = 0;
		}
	}
}
int main() {
	ios_base::sync_with_stdio(0); cin.tie(0);
	init();
	bfs();
	cout << shark.time;
	return 0;
}