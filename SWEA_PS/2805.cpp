#include <cstdio>
#include <cstring>
#define MAX 49
using namespace std;
int n;
int map[MAX][MAX];
int calcProfit() {
	int ret=0;
	int nHalf = n/2;
	for (int y=0; y<nHalf; y++) 
		for (int x=nHalf-y; x<=nHalf+y; x++) 
			ret += map[y][x];
		
	for (int y=nHalf; y>=0; y--) 
		for (int x=nHalf-y; x<=nHalf+y; x++)
			ret += map[n-1-y][x];
			
	return ret;
}
void solve() {
	int t;
	scanf("%d", &t);
	for (int i=1; i<=t; i++) {
		scanf("%d", &n);
		memset(map, 0, sizeof(map));
		for (int y=0; y<n; y++)	
			for (int x=0; x<n; x++) 
				scanf("%1d", &map[y][x]);
		
		printf("#%d %d\n", i, calcProfit());
	}
}
int main(int argc, char** argv) {
	solve();
	return 0;
}
