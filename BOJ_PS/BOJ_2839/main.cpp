#include <iostream>
using namespace std;
int main(int argc, char** argv) {
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	int n, ans=0;
	cin>>n;
	
	// 5·Î ³ª´« ¸ò 
	int nQuotient = n / 5;
	while(nQuotient >= 0) {
		int nRemainder = n  - (nQuotient * 5);
		if (nRemainder % 3 == 0) {
			ans = nQuotient + (nRemainder / 3);
			break;
		}
		nQuotient--;
	}
	ans==0 ? cout<<-1<<"\n" : cout<<ans<<"\n";
	return 0;
}
