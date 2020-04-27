#include <iostream>
#include <queue>
#include <vector>
#include <cstring>
#include <algorithm>
using namespace std;
bool flag;
int n, l, r, ans;
int dy[] = { 0, -1, 0, 1 };
int dx[] = { 1, 0, -1, 0 };
int map[50][50];
bool visit[50][50];
vector<pair<int, int> > v;
void init() {
	cin >> n >> l >> r;
	for (int y = 0; y < n; y++) {
		for (int x = 0; x < n; x++) {
			cin >> map[y][x];
		}
	}
}
void bfs(int y, int x) {
	int count = 1, sum = map[y][x];
	queue<pair<int, int> > q;
	q.push(make_pair(y, x));
	v.push_back(make_pair(y, x));
	visit[y][x] = 1;
	
	while (!q.empty()) {
		int y = q.front().first;
		int x = q.front().second;
		q.pop();

		for (int i = 0; i < 4; i++) {
			int ny = y + dy[i];
			int nx = x + dx[i];
			if (ny < 0 || nx < 0 || ny >= n || nx >= n || visit[ny][nx]) continue;

			int diff = abs(map[y][x] - map[ny][nx]);
			if (diff >= l && diff <= r) {
				visit[ny][nx] = 1;
				sum += map[ny][nx];
				count++;
				q.push(make_pair(ny, nx));
				v.push_back(make_pair(ny, nx));
			}
		}
	}

	if (v.size() > 1) {
		flag = 1;
		int updateValue = sum / count;
		for (int i = 0; i < v.size(); i++) map[v[i].first][v[i].second] = updateValue;	
	}
	v.clear();
}
int main() {
	ios_base::sync_with_stdio(0); cin.tie(0);
	init();
	while (true) {
		memset(visit, 0, sizeof(visit));
		flag = 0;
		for (int y = 0; y < n; y++) {
			for (int x = 0; x < n; x++) {
				if (visit[y][x]) continue;
				bfs(y, x);
			}
		}
		if (flag) ans++;
		else break;
	}
	cout << ans << "\n";
	return 0;
}