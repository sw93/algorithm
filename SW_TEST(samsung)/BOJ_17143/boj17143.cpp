#include <iostream>
#include <vector>
using namespace std;
struct SHARK {
	int r, c, s, d, z;
	bool dead;
};
int r, c, m;
int map[101][101];
const int dy[] = { -1, 1, 0, 0 };
const int dx[] = { 0, 0, 1, -1 };
vector<SHARK> v;

void init() {
	cin >> r >> c >> m;

	// 1������ ����
	v.push_back({ 0,0,0,0,0,0 });
	for (int i = 1; i <= m; i++) {
		SHARK shark;
		cin >> shark.r >> shark.c >> shark.s >> shark.d >> shark.z;
		shark.dead = 0;
		shark.d -= 1;
		v.push_back(shark);
		map[shark.r][shark.c] = i;
	}
}

int catchShark(int x) {
	int ret = 0;
	for (int y = 1; y <= r; y++) {
		if (map[y][x] != 0) {
			ret = v[map[y][x]].z;
			v[map[y][x]].dead = 1;
			map[y][x] = 0;

			break;
		}
	}
	return ret;
}

void moveShark() {
	for (int i = 1; i <= m; i++) {

		// ���� ���� �ǳʶڴ�
		if (v[i].dead) continue;

		// ������ ��� ����
		int y = v[i].r;
		int x = v[i].c;
		int speed = v[i].s;
		int dir = v[i].d;
		int size = v[i].z;

		// ���� ������ ��� ���� ��ġ �ʱ�ȭ
		if (map[y][x] == i) map[y][x] = 0;

		// ��, �Ʒ�
		if (dir == 0 || dir == 1) {
			speed = speed%((r - 1) * 2);
			
			while (speed--) {
				int ny = y + dy[dir];
				if (1 > ny || ny > r) dir = 1 - dir;
				y += dy[dir];
			}
		} else { // ������ ����
			speed = speed%((c - 1) * 2);

			while (speed--) {
				int nx = x + dx[dir];
				if (1 > nx || nx > c) dir = 5 - dir;
				x += dx[dir];
			}
		}

		// �̵��� ��� ��ġ �ֽ�ȭ
		v[i].r = y;
		v[i].c = x;
		v[i].d = dir;

		// �̵��� ��ġ�� ��ĭ�� ��� => ��ġ �̵�
		if (map[y][x] == 0) {
			map[y][x] = i;
		} 

		// �̵��� ��ġ�� �̹� �̵��� �Ϸ��� �� �ִ� ��� => ��Ƹ԰ų� ��� ����
		else if (i > map[y][x]) { 

			// �̵��� ����� ����� �� ū ���
			if (size > v[map[y][x]].z) {
				v[map[y][x]].dead = 1;
				map[y][x] = i;
			}

			// �̵��� ����� ����� �� ���� ��� 
			else {
				v[i].dead = 1;
			}
		} 
		
		// �̵��� ��ġ�� ���� �̵� �� �� �� �ִ� ��� => ���Ŀ� �� ó���ϱ� ������ ������ ����
		else { 
			map[y][x] = i;
		}
	}
}
int main() {
	ios_base::sync_with_stdio(0); cin.tie(0);
	init();

	// ���� ó��
	if (m == 0) {
		cout << 0;
		return 0;
	}

	int ans = 0;
	for (int x = 1; x <= c; x++) {
		ans += catchShark(x);
		moveShark();
	}
	cout << ans;
	return 0;
}