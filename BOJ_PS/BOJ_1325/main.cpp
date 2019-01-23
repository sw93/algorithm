#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <cstring>
using namespace std;
int n,m,maxValue;
vector<vector<int> > network;
vector<int> result;
bool visit[10001];
/**
 * 모든 노드를 탐색하고, 탐색 가능한 최댓값을 구하는 문제입니다.
 * A가 B를 신뢰할 경우, B를 해킹하면 A도 해킹이 가능하다.
 * 즉, A가 B를 신뢰한다는 것을 다르게 말하면, B → A 로 연결된 방향 그래프인것이죠.
 * 먼저 입력을 받을때 신뢰 관계를 network에 저장합니다.
 * 이후 컴퓨터 개수가 n개이기 때문에 bfs를 n번 호출하여 해킹가능한 최대 컴퓨터를 구합니다.
 * 해킹가능한 최대 결과값이 같은 컴퓨터가 존재할 수 있으므로 결과 벡터를 생성해 결과값을 저장합니다.
 * 이때 가장 큰 값을 카운트 한 값과 비교하여 같으면 결과벡터에 추가를 하고,
 * 카운트 값이 크면 결과벡터를 초기화 한후 push를 합니다.
 * 조금만 생각해 보면 알 수 있는데, 최대 컴퓨터를 구하는 것이므로 새로운 최대 컴퓨터가 있다면 이전 결과는 모두 필요가 없기 때문입니다.
 * 생각보다 어려웠던 문제인데 bfs말고 dfs로도 풀이가 가능하니 최대한 빨리 dfs로 풀이하고 업데이트 하겠습니다.
 */
void bfs(int s) {
    queue<int> q;
    q.push(s);
    visit[s]=1;
    int cnt=0;
    while(!q.empty()) {
        int src=q.front();
        q.pop();
        for(int i=0; i<network[src].size(); i++) {
            int dest=network[src][i];
            if(!visit[dest]) {
                visit[dest]=1;
                q.push(dest);
                cnt++;
            }
        }
    }
    if(maxValue<cnt) {
        maxValue=cnt;
        result.clear();
        result.push_back(s);
    } else if(maxValue==cnt) {
        result.push_back(s);
    }
}
int main() {
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cin>>n>>m;
    network.resize(n+1);
    int src,dest;
    for(int i=0; i<m; i++) {
        cin>>src>>dest;
        network[dest].push_back(src);
    }
    for(int i=1; i<=n; i++) {
        memset(visit, 0, sizeof(visit));
        bfs(i);
    }
    sort(result.begin(), result.end());
    for(int i=0; i<result.size(); i++) {
        cout<<result[i]<<" ";
    }
    return 0;
}