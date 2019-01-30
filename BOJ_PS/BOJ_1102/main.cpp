#include <iostream>
#include <algorithm>
#include <cstring>
#define MAX 16
#define INF 0x3f3f3f3f
using namespace std;
int n, on, onCnt, p;
int cost[MAX][MAX];
int dp[1<<MAX];
/**
 * 처음에 그리디적으로 접근하다가 알고리즘 분류에 dp가 있어서 생각을 바꾸고 다시 푼 문제.
 * 이제부터 알고리즘 분류를 보면 안되겠다... dp문제와 비트마스크 문제를 좀 기계식으로 풀었다.
 * 이 문제는 외판원 순회와 굉장히 유사하고 답도 거의 유사하다.
 * 처음 input을 받을때 켜져있는 발전소가 어떤 것인지 알기 위해 'Y'를 입력받으면 on변수에 해당 비트를 켜준다.
 * 만약 'YNN'을 입력 받았다면 1<<0 이므로 on은 0001의 상태가 되어 첫번째 발전소만 켜진 것을 의미한다.
 * dp배열은 인덱스를 켜져있는 발전소 상태를 참조하여 값으로 최소 비용을 넣어준다.
 * 즉 dp[idx]는 최소 p개 키는데 사용하는 최소비용이며 idx는 현재 켜진 발전소 상태를 의미한다.
 * 만약 모든 발전소가 꺼져있거나 p가 0인경우는 비용이 없으므로 0을 리턴하게 되며 현재 켜져있는 발전소에 대해서만
 * solve함수를 호출한다. solve함수에서는 가장먼저 켜져있는 발전소의 index를 먼저 찾고 꺼져있는 발전소의 index를 찾는다.
 * 꺼진 발전소를 키고 dp값에 저장하는 방식으로 풀이하면 된다.
 *
 * 처음에 시간초과가 났는데 dp배열을 INF로 초기화 해주지 않았다. 왜 시간초과가 나는지는 모르겠지만 앞으로는 그냥 일단
 * 초기화 하고 사용하도록 해야겠다.
 */
int solve(int state, int cnt) {
    if(cnt>=p) return 0;
    int &ret=dp[state];
    if(ret!=INF)  return ret;
    for(int i=0; i<n; i++) {
        if(!(state & (1<<i))) continue;
        for(int j=0; j<n; j++) {
            if(state & (1<<j))   continue;
            ret=min(ret, solve(state | (1<<j), cnt+1) + cost[i][j]);
        }
    }
    return ret;
}
int main() {
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cin>>n;
    for(int i=0; i<n; i++)
        for(int j=0; j<n; j++)
            cin>>cost[i][j];
    for(int i=0; i<n; i++) {
        char c;
        cin>>c;
        if(c=='Y') on|=(1<<i), onCnt++;
    }
    cin>>p;
    memset(dp, INF, sizeof(dp));
    int answer=solve(on, onCnt);
    if(answer >= INF) answer=-1;
    cout<<answer;
    return 0;
}