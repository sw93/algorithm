#include <iostream>
#include <string.h>
#define MAX 246913
using namespace std;

/**
* n <= 123456 까지의 자연수 이므로 123456 * 2까지의 소수를 에라토스테네스체로 
* 먼저 구해 저장하고 while문을 돌면서 0이 나올때까지 그 값을 사용하는 방식으로 풀이. 
*/
bool isPrime[MAX];

void eratosthenes() {
	memset(isPrime, 1, sizeof(bool) * MAX);
	for (int i=2; i<=MAX; i++) {
		if (isPrime[i]) {
			for (int j=i*2; j<=MAX; j+=i) {
				isPrime[j] = 0;
			}
		}
	}
} 
int main(int argc, char** argv) {
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	int n;
	eratosthenes();
	while(true) {
		int ans=0;
		cin>>n;
		if (n==0) {
			break;
		}
		for (int i=n+1; i<=2*n; i++) {
			if (isPrime[i]) {
				ans++;
			}
		}
		cout<<ans<<"\n";
	}
	return 0;
}
