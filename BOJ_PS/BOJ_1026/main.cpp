#include <iostream>
#include <algorithm>
using namespace std;
bool desc(int a, int b) {
    return a>b;
}
/**
 * a배열과 b배열의 곱을 최소한으로 하는 문제입니다.
 * 가장 큰 값과 가장 작은 값을 곱하면 최소값이 나오는 것을 이용해 정렬을 사용하면
 * 쉽게 풀 수 있는 문제입니다. 이문제에서 b에 있는 수는 재배열하면 안된다고 나와있어 당황스러웟는데
 * 배열을 따로 출력하거나 하지 않기 때문에 일단 제출하니 맞았습니다가 나왔습니다. 다른 풀이도
 * 오름차순, 내림차순 소팅을 하는 것을 보아 제가 생각하는 재배열과 문제에서 말하는 것은 다른것 같습니다.
*/
int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    int n;
    cin>>n;
    int a[n], b[n], answer=0;
    for(int i=0; i<n; i++) cin>>a[i];
    for(int i=0; i<n; i++) cin>>b[i];
    sort(a, a+n);
    sort(b, b+n, desc);
    for(int i=0; i<n; i++) answer+=a[i]*b[i];
    cout<<answer;
    return 0;
}