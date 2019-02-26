#include <iostream>
#include <string>
#include <algorithm>
using namespace std;
string dp[101][101];
/**
 * 조합공식을 이용해 풀이했지만 자꾸 틀렸습니다가 나와 멘붕온 문제
 * 이유는 unsingend long long의 범위도 넘기 때문이였다.
 * 결국 구글링을 통해 solve...
 */
string addNum(string a, string b) {
    unsigned long long int sum = 0;
    string ret;
    while(!a.empty() || !b.empty() || sum) {
        if(!a.empty()) {
            sum+=a.back() - '0';
            a.pop_back();
        }
        if(!b.empty()) {
            sum+=b.back() - '0';
            b.pop_back();
        }
        ret.push_back((sum%10) + '0');
        sum/=10;
    }
    reverse(ret.begin(), ret.end());
    return ret;
}
string combination(int n, int r) {
    if(n==r || r==0)
        return "1";
    string &ret = dp[n][r];
    if(ret != "")
        return ret;
    ret=addNum(combination(n-1, r-1), combination(n-1, r));
    return ret;
}
int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    int n,m;
    cin>>n>>m;
    cout<<combination(n,m);
    return 0;
}