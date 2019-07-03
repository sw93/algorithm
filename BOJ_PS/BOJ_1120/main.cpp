#include <iostream>
#include <string>
#define MAX 987654321
using namespace std;
int min(int a, int b) {
	return a>=b ? b : a;
}
int main(int argc, char** argv) {
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	string x,y;
	int ans=MAX;
	cin>>x>>y;
	for (int i=0; i<= y.size() - x.size(); i++) {
		int cnt = 0;
		int yIdx=i;
		for (int j=0; j < x.size(); j++, yIdx++) {
			if (x[j] == y[yIdx]) continue;
			cnt++;
		}
		ans = min(ans, cnt);
	}
	cout<<ans;
	return 0;
}
