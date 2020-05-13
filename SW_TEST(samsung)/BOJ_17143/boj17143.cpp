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

	// 1번부터 시작
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

		// 죽은 상어는 건너뛴다
		if (v[i].dead) continue;

		// 움직일 상어 정보
		int y = v[i].r;
		int x = v[i].c;
		int speed = v[i].s;
		int dir = v[i].d;
		int size = v[i].z;

		// 현재 움직일 상어 기존 위치 초기화
		if (map[y][x] == i) map[y][x] = 0;

		// 위, 아래
		if (dir == 0 || dir == 1) {
			speed = speed%((r - 1) * 2);
			
			while (speed--) {
				int ny = y + dy[dir];
				if (1 > ny || ny > r) dir = 1 - dir;
				y += dy[dir];
			}
		} else { // 오른쪽 왼쪽
			speed = speed%((c - 1) * 2);

			while (speed--) {
				int nx = x + dx[dir];
				if (1 > nx || nx > c) dir = 5 - dir;
				x += dx[dir];
			}
		}

		// 이동한 상어 위치 최신화
		v[i].r = y;
		v[i].c = x;
		v[i].d = dir;

		// 이동한 위치가 빈칸인 경우 => 위치 이동
		if (map[y][x] == 0) {
			map[y][x] = i;
		} 

		// 이동한 위치에 이미 이동을 완료한 상어가 있는 경우 => 잡아먹거나 잡아 먹힘
		else if (i > map[y][x]) { 

			// 이동한 상어의 사이즈가 더 큰 경우
			if (size > v[map[y][x]].z) {
				v[map[y][x]].dead = 1;
				map[y][x] = i;
			}

			// 이동한 상어의 사이즈가 더 작은 경우 
			else {
				v[i].dead = 1;
			}
		} 
		
		// 이동한 위치에 아직 이동 안 한 상어가 있는 경우 => 이후에 재 처리하기 때문에 뒤집어 씌움
		else { 
			map[y][x] = i;
		}
	}
}
int main() {
	ios_base::sync_with_stdio(0); cin.tie(0);
	init();

	// 예외 처리
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