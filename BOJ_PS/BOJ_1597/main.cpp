#include <iostream>
#include <queue>
#define MAX 100001
using namespace std;
int n,k,result;
bool visit[MAX];
int dx[]={-1,0,1};
/**
 * DFS문제인지 BFS문제인지 구분하기!
 *
 * bfs
 * 가장 최단 경로를 구하고 싶을때 사용한다.(출발->도착)
 * 즉, 초기상태로부터 목표값까지의 최소 횟수를 구하고 싶을때 사용한다.
 *
 * dfs
 * 모든 조건(가능성)을 탐색할때 사용한다.
 * 즉, 어떤 방법이 가장 좋은 방법인지 알고싶을때 사용
 *
 * bfs와 dfs 모두 사용
 * 그래프 상 끊어진 연결이 없는지 확인하고자 할때 두가지 모두 사용가능하다.
 * 즉, 주어진 곳에서 다른 곳으로 도달할 수 있는지 알고 싶을때 사용한다.
 */

/**
 * 위 설명을 보면 최단 거리, 최소횟수는 BFS를 이용해야 하는 것을 알 수 있습니다.
 * 하지만 저는 몰랐어요 ㅠㅠ 저내용을 ㅠㅠ DFS로 풀이하다 무한루프에 빠져 프로그램이 죽어 BFS로 풀이하였습니다.
 * 문제 자체는 간단합니다. 현재 위치에서 목표 위치로 이동하는데 최소카운트를 출력하는 문제입니다.
 * bfs로 풀이하기 위해 큐를 하나 생성하는데 큐의 현재위치와 현재 큐에서 얼만큼 움직여야 하는지를 알기 위해 pair로 선언해줍니다.
 * 방문할 때마다 몇번만에 해당 위치에 도착했는지 카운트를 해주는 것입니다.(문제의 키포인트!)
 * 즉, 2에서 5를 가기 위해서 2*2를 통해 4가 되었으면 4번 위치의 카운트는 1입니다.
 * 이후 4->5로 가기위해 4+1로 5가 되면 5의 카운트는 1+1이 되어 2가 되겠죠.
 */
void bfs(int s) {
    queue<pair<int, int> > q;
    q.push(make_pair(s,0));
    visit[s]=1;
    while(!q.empty()) {
        int x=q.front().first;
        int cnt=q.front().second;
        q.pop();
        if(x==k) {
            result=cnt;
            return;
        }
        for(int i=0; i<3; i++) {
            int nx;
            if(dx[i]==0)    nx=x*2;
            else    nx=x+dx[i];
            if(nx<0 || nx>=MAX || visit[nx]) continue;
            q.push(make_pair(nx, cnt+1));
            visit[nx]=1;
        }
    }
}
int main() {
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cin>>n>>k;
    bfs(n);
    cout<<result;
    return 0;
}