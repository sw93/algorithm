#include <iostream>
#include <vector>
#include <cstring>
#include <algorithm>
using namespace std;
int r, c, k, rowSize = 3, colSize = 3;
int a[100][100];
int numberCount[101];
void init() {
	cin >> r >> c >> k;
	r--, c--;
	for (int y = 0; y < 3; y++) {
		for (int x = 0; x < 3; x++) {
			cin >> a[y][x];
		}
	}
}
void rCalc() {
	int newColSize = 0;

	for (int y = 0; y < rowSize; y++) {
		memset(numberCount, 0, sizeof(numberCount));
		vector<pair<int, int> > v;
		for (int x = 0; x < colSize; x++) numberCount[a[y][x]]++;

		for (int i = 1; i <= 100; i++) {
			if (numberCount[i] == 0) continue;
			v.push_back(make_pair(numberCount[i], i));
		}
		
		sort(v.begin(), v.end());
		int curColSize = v.size() * 2;
		newColSize = max(newColSize, curColSize);

		int xIndex = 0;
		for (vector<pair<int, int>>::iterator it = v.begin(); it != v.end(); it++) {
			a[y][xIndex] = it->second;
			a[y][xIndex + 1] = it->first;
			xIndex += 2;
		}
		for (int x = curColSize; x < colSize; x++) a[y][x] = 0;
		
	}
	colSize = newColSize;
}
void cCalc() {
	int newRowSize = 0;
	
	for (int x = 0; x < colSize; x++) {
		memset(numberCount, 0, sizeof(numberCount));
		vector<pair<int, int> > v;
		for (int y = 0; y < rowSize; y++) numberCount[a[y][x]]++;

		for (int i = 1; i <= 100; i++) {
			if (numberCount[i] == 0) continue;
			v.push_back(make_pair(numberCount[i], i));
		}

		sort(v.begin(), v.end());
		int curRowSize = v.size() * 2;
		newRowSize = max(newRowSize, curRowSize);

		int yIndex = 0;
		for (vector<pair<int, int>>::iterator it = v.begin(); it != v.end(); it++) {
			a[yIndex][x] = it->second;
			a[yIndex + 1][x] = it->first;
			yIndex += 2;
		}
		for (int y = curRowSize; y < rowSize; y++) a[y][x] = 0;
	}
	rowSize = newRowSize;
}
void solve() {
	int ans = 0;
	while (1) {
		if (ans > 100) {
			cout << -1 << "\n";
			break;
		} else if (a[r][c] == k) {
			cout << ans << "\n";
			break;
		}
		if (rowSize >= colSize) rCalc();
		else cCalc();
		ans++;
	}
}
int main() {
	ios_base::sync_with_stdio(0); cin.tie(0);
	init();
	solve();
	return 0;
}