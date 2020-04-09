#include <iostream>
using namespace std;
int n, m, dy, dx, k;
int dice[6] = { 0 };	// 위 아래 오른쪽 왼쪽 앞 뒤
int map[20][20];
void swap(int index1, int index2) {
	int temp = dice[index1];
	dice[index1] = dice[index2];
	dice[index2] = temp;
}
bool moveDiceOnMap(int cmd) {
	// 1:동, 2:서, 3:북, 4:남
	switch (cmd) {
		// 동
		case 1:
			if (dy < 0 || dx + 1 < 0 || dy >= n || dx + 1 >= m) {
				return false;
			} else {
				dx++;
				swap(0, 2);
				swap(1, 3);
				swap(0, 1);
			}
			break;
		// 서
		case 2:
			if (dy < 0 || dx - 1 < 0 || dy >= n || dx - 1 >= m) {
				return false;
			} else {
				dx--;
				swap(0, 2);
				swap(1, 3);
				swap(2, 3);
			}
			break;
		// 북
		case 3:
			if (dy - 1 < 0 || dx < 0 || dy - 1 >= n || dx >= m) {
				return false;
			} else {
				dy--;
				swap(0, 5);
				swap(1, 4);
				swap(0, 1);
			}
			break;
		// 남
		case 4:
			if (dy + 1 < 0 || dx < 0 || dy + 1 >= n || dx >= m) {
				return false;
			} else {
				dy++;
				swap(0, 5);
				swap(1, 4);
				swap(4, 5);
			}
			break;
	}
	return true;
}
int main() {
	ios_base::sync_with_stdio(0); cin.tie(0);
	cin >> n >> m >> dy >> dx >> k;
	for (int y = 0; y < n; y++) {
		for (int x = 0; x < m; x++) {
			cin >> map[y][x];
		}
	}
	 
	int cmd;
	while (k--) {
		cin >> cmd;

		// 주사위를 움직임
		if (!moveDiceOnMap(cmd)) continue;
		
		int mapNumber = map[dy][dx];
		if (mapNumber == 0) {
			map[dy][dx] = dice[1];
		} else {
			dice[1] = map[dy][dx];
			map[dy][dx] = 0;
		}
		cout << dice[0] << "\n";
	}
	return 0;
}