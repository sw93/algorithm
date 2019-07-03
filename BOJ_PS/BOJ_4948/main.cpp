#include <iostream>
#include <string.h>
#define MAX 246913
using namespace std;

/**
* n <= 123456 ������ �ڿ��� �̹Ƿ� 123456 * 2������ �Ҽ��� �����佺�׳׽�ü�� 
* ���� ���� �����ϰ� while���� ���鼭 0�� ���ö����� �� ���� ����ϴ� ������� Ǯ��. 
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
