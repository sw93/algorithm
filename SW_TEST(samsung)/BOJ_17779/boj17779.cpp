#include <iostream>
#include <vector>
#include <algorithm>
#define INF 987654321
using namespace std;
int n, ans = INF;
int map[20][20];
int tempMap[20][20];
vector<pair<int, int> > v;
void init() {
	cin >> n;
	for (int y = 0; y < n; y++) {
		for (int x = 0; x < n; x++) {
			cin >> map[y][x];
		}
	}
}
bool checkBoard(int y, int x, int d1, int d2) {

	// 3번 꼭지점
	if (y + d1 >= n || x - d1 < 0) return false;

	// 2번 꼭지점
	if (y + d2 >= n || x + d2 >= n) return false;

	// 4번 꼭지점
	if (y + d1 + d2 >= n || x - d1 + d2 < 0) return false;
	return true;
}
void calc() {
	vector<int> ret(5, 0);
	for (int y = 0; y < n; y++) {
		for (int x = 0; x < n; x++) {
			if (tempMap[y][x] == 1) ret[0] += map[y][x];
			else if (tempMap[y][x] == 2) ret[1] += map[y][x];
			else if (tempMap[y][x] == 3) ret[2] += map[y][x];
			else if (tempMap[y][x] == 4) ret[3] += map[y][x];
			else if (tempMap[y][x] == 5) ret[4] += map[y][x];
		}
	}

	sort(ret.begin(), ret.end());
	int diff = ret[4] - ret[0];
	ans = min(ans, diff);
}
void solve() {

	// 5번 지역구로 모두 초기화 (1, 2, 3, 4번 지역구가 아니면 5번 지역구)
	for (int y = 0; y < n; y++) {
		for (int x = 0; x < n; x++) {
			tempMap[y][x] = 5;
		}
	}

	// 1번 지역구
	int minusCount = 0;
	for (int y = 0; y < v[1].first; y++) {
		if (y >= v[0].first) minusCount++;
		for (int x = 0; x <= v[0].second - minusCount; x++) {
			tempMap[y][x] = 1;
		}
	}

	// 2번 지역구
	minusCount = 0;
	for (int y = 0; y <= v[2].first; y++) {
		if (y > v[0].first) minusCount++;
		for (int x = v[0].second + minusCount + 1; x < n; x++) {
			tempMap[y][x] = 2;
		}
	}

	// 3번 지역구
	minusCount = 0;
	for (int y = n - 1; y >= v[1].first; y--) {
		if (y < v[3].first) minusCount++;
		for (int x = 0; x < v[3].second - minusCount; x++) {
			tempMap[y][x] = 3;
		}
	}

	// 4번 지역구
	minusCount = 0;
	for (int y = n - 1; y > v[2].first; y--) {
		if (y <= v[3].first) minusCount++;
		for (int x = v[3].second + minusCount; x < n; x++) {
			tempMap[y][x] = 4;
		}
	}

	calc();
	v.clear();
}
int main() {
	ios_base::sync_with_stdio(0); cin.tie(0);
	init();
	for (int y = 0; y < n; y++) {
		for (int x = 0; x < n; x++) {

			// d1 = 왼쪽 대각선 이동
			// 3번 꼭지점 = (y+d1, x-d1)
			// x-d1값이 0보다 크거나 같아야 함 (x - d1 >= 0)
			// 따라서 d1 <= x
			for (int d1 = 1; d1 <= x; d1++) {

				// d2 = 오른쪽 대각선 이동
				// 2번 꼭지점 = (y+d2, x+d2)
				// x+d2값이 n보다 작거나 같아야 함 (x + d2 <= n)
				// 따라서 d2 <= n-x
				for (int d2 = 1; d2 < n - x; d2++) {
					if (checkBoard(y, x, d1, d2)) {
						// 선거구 경계 위치
						v.push_back(make_pair(y, x));
						v.push_back(make_pair(y + d1, x - d1));
						v.push_back(make_pair(y + d2, x + d2));
						v.push_back(make_pair(y + d1 + d2, x - d1 + d2));
						solve();
					}
				}
			}
		}
	}
	cout << ans;
	return 0;
}