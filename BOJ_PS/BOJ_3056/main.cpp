#include <iostream>
#include <algorithm>
#define MAX 20
using namespace std;
int n;
double p[MAX][MAX], dp[1<<MAX];
/**
 * dp + bitmask문제는 유형이 비슷한거 같다. 지금까지 비슷한 유형만 푼거일수도...
 * 입력에서의 행을 요원, 열을 확률로 생각하면 되는데 0번 요원은 100, 1번요원은 13, 2번요원은 90을
 * 계산해주면 출력값이 나온다. 처음에 이해를 잘못해서 출력이 어떻게 나오는지 고생...
 * x축을 기준으로 탐색을 해주면서 방문을 안한 확률에 대해서만 방문표시를 하고 확률을 곱해준다.
 * 기저사례에서 확률을 곱해주기 때문에 0을 리턴하면 안되기 때문에 1을 리턴해주면 된다.
 * 이 문제를 처음 구현했을때 시간초과가 나왔는데 처음에는 이해를 못했다.
 * 문제는 기저사례였다. 기존에는 if(y==n)  return 1; 이런식으로 했었는데
 * bitmask를 사용해서 if(state == (1<<n)-1)로 조건을 바꿔주니 맞았다.
 * 아마 y==n이면 제때 빠져나오지 못하는 경우가 존재하는것 같다.
 * 그리고 이 문제에서 출력형식이 뭔가 잘못된거 같다.
 * 오차범위가 소수점 6자리인데 출력은 5자리까지만 나와있다.
 * 그런데 5자리로만 출력하면 틀렸습니다가 나온다 ㅡㅡ (이해를 잘못하고 있는건가?)
 */
double solve(int y, int state) {
    if(state == (1<<n)-1)   return 1;
    double &ret=dp[state];
    if(ret!=0.0)  return ret;
    for(int i=0; i<n; i++) {
        if((state & (1<<i)))    continue;
        ret=max(ret, solve(y+1, state|(1<<i)) * p[y][i]);
    }
    return ret;
}
int main() {
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0); cout.precision(6); cout<<fixed;
    cin>>n;
    for(int y=0; y<n; y++)
        for(int x=0; x<n; x++) {
            cin >> p[y][x];
            p[y][x] /= 100.0;
        }
    cout<<solve(0, 0) * 100.0<<endl;
    return 0;
}