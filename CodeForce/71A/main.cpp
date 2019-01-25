#include <iostream>
#include <string>
// http://codeforces.com/problemset/problem/71/A
using namespace std;
int main() {
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    int tc;
    cin>>tc;
    string str;
    while(tc--) {
        cin>>str;
        if(str.length()>10) cout<<str[0]<<str.length()-2<<str[str.length()-1]<<endl;
        else    cout<<str<<endl;
    }
    return 0;
}