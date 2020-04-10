#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int n, ans = -1;
int t[21], p[21];
void solve(int day, int sum) {
    if (day == n + 1) {
        ans = max(ans, sum);
        return;
    }
    if (day > n + 1) return;
    solve(day + 1, sum);
    solve(day + t[day], sum + p[day]);
}
int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> t[i] >> p[i];
    }
    solve(1, 0);
    cout << ans << "\n";
    return 0;
}