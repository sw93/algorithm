#include <string>
#include <algorithm>
#include <iostream>
using namespace std;
int n, result;
string num;
/**
 *  전체탐색을 이용하여 풀이하였습니다.
 *  입력받은 교환가능 횟수만큼 교환을 한뒤 가장 큰값을 result에 담아
 *  출력해주는 방식입니다.
 */
void dfs(int cur, int cnt) {
    if(cnt==n) {
        result=max(result, stoi(num));
        return;
    }
    for(int i=cur; i<num.size(); i++) {
        for(int j=i+1; j<num.size(); j++) {
            if(num[i] <= num[j]) {
                swap(num[i], num[j]);
                dfs(i, cnt + 1);
                swap(num[i], num[j]);
            }
        }
    }
}
int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    int tc;
    cin>>tc;
    for(int i=1; i<=tc; i++) {
        cin>>num>>n;
        result=0;
        dfs(0,0);
        cout<<"#"<<i<<" "<<result<<"\n";
    }
    return 0;
}