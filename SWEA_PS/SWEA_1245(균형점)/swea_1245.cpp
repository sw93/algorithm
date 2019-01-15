#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
struct coordinates {
	int x;
	int y;
};


coordinates map[11];

// 인력 F = G*m1*m2 / (d*d)
// G = 양의 상수
int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout << fixed;
	cout.precision(10);
	int tc, n;
	cin >> tc;
	for (int t = 1; t <= tc; t++) {
		cin >> n;
		for (int i = 1; i <= n; i++)
			cin >> map[i].x;
		for (int i = 1; i <= n; i++)
			cin >> map[i].y;

		cout << "#" << t << " ";
		for (int i = 1; i < n; i++) {
			double x;
			double left = map[i].x;
			double right = map[i + 1].x;

			int cnt = 0;
			while (true) {
				x = (left + right) / 2.0;
				double lf = 0;
				double rf = 0;
				for (int j = 1; j <= i; j++)
					lf += (map[j].y) / ((map[j].x - x) * (map[j].x - x));
				for(int j=i+1; j<=n; j++)
					rf += (map[j].y) / ((map[j].x - x) * (map[j].x - x));

				if (cnt++ == 100) {
					cout << x;
					break;
				}

				if (lf > rf)
					left = x;
				else
					right = x;
			}
		}
		cout << endl;
	}
	return 0;
}