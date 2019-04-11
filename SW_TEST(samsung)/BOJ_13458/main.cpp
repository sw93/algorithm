#include <iostream>
using namespace std;
int a[1000001];
int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    int n, b, c;
    long long ans=0;
    cin>>n;
    for(int i=0; i<n; i++) cin>>a[i];
    cin>>b>>c;
    for(int i=0; i<n; i++) {
        ans++;
        a[i] -= b;
        if(a[i]<=0) continue;
        ans += (a[i] % c == 0 ? a[i] / c : a[i] / c + 1);
    }
    cout<<ans<<endl;
    return 0;
}