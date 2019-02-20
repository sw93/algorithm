#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;
/**
 * vector를 2개 사용해서 단순 비교한 뒤 같다면 answer에 추가해주는 방식으로 진행했더니
 * 시간초과가 났다. 2개를 사용하지 않고 하나에 입력을 받아 compare해준 뒤 같다면
 * answer에 추가해주는 방식으로 풀이. 사실 문제이름이 재미있어서 선택했는데
 * 너무 쉬운문제였다는 것이 함정.
 */
int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    int n,m;
    cin>>n>>m;
    vector<string> dbj(n+m), answer;

    for(int i=0; i<n+m; i++)
        cin>>dbj[i];
    sort(dbj.begin(), dbj.end());

    for(int i=1; i<n+m; i++)
        if(dbj[i].compare(dbj[i-1]) == 0)
            answer.push_back(dbj[i]);

    cout<<answer.size()<<"\n";
    for(string name : answer) cout<<name<<"\n";

    return 0;
}