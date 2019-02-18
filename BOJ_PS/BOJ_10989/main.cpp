#include <iostream>
using namespace std;
int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    int n,input;
    int num[10001]={0,};
    cin>>n;
    for(int i=0; i<n; i++) {
        cin>>input;
        num[input]++;
    }
    for(int i=1; i<=10000; i++) {
        while(num[i]--) {
            cout<<i<<"\n";
        }
    }
    return 0;
}