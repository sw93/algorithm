#include <iostream>
using namespace std;
int main(int argc, char** argv) {
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	int coins[] = {500, 100, 50, 10, 5, 1};
	int nCost, ans=0;
	cin>>nCost;
	int nRemainder = 1000 - nCost;
	for (int i=0; i<6; i++) {
		while (nRemainder - coins[i] >= 0) {
			nRemainder -= coins[i];
			ans++;
			if (nRemainder == 0) {
				break;
			}
		}
	}
	cout<<ans;
	return 0;
}
