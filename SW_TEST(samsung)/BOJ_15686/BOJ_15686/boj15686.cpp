#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
struct pos {
	int y, x;
};
int n, m, ans=987654321;
int map[50][50];
vector<pos> chicken, house, selectedChicken;
void dfs(int index) {
	if (selectedChicken.size() == m) {
		int distSum = 0;
		for (int i = 0; i < house.size(); i++) {
			int minDist = 987654321;
			for (int j = 0; j < selectedChicken.size(); j++) {
				minDist = min(minDist, abs(house[i].y - selectedChicken[j].y) + abs(house[i].x - selectedChicken[j].x));
			}
			distSum += minDist;
		}
		ans = min(ans, distSum);
		return;
	}

	for (int i = index; i < chicken.size(); i++) {
		selectedChicken.push_back(chicken[i]);
		dfs(i+1);
		selectedChicken.pop_back();
	}
}
void init() {
	cin >> n >> m;
	for (int y = 0; y < n; y++) {
		for (int x = 0; x < n; x++) {
			cin >> map[y][x];
			if (map[y][x] == 1) house.push_back({ y,x });
			else if (map[y][x] == 2) chicken.push_back({ y,x });
		}
	}
}
int main() {
	ios_base::sync_with_stdio(0); cin.tie(0);
	init();
	dfs(0);
	cout << ans << "\n";
	return 0;
}