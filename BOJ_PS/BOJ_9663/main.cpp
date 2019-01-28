#include <iostream>
#include <cmath>
#define MAX 16
using namespace std;
int n,result;
int map[MAX];
/**
 * 퀸은 행,열,대각방향으로 공격할 수 있는 기물입니다. 따라서 각 행, 열에는 퀸이 오직 1개만 위치할 수 있습니다.
 * 대각선은 가로의차이가 세로의 차이와 같으면 대각방향에 위치할 수 없는 것으로 판단할 수 있습니다.
 * => 행렬을 그린뒤 row+col의 값을 모두 그려보면 왜 그런지 알 수 있습니다. (row+col)의 값이 대각성분끼리 같습니다.
 * 탐색할 수 있는 경우를 모두 탐색하되 유망한지를 참조하여 탐색합니다.
 * 1차원 배열로 문제를 풀이하는게 처음에 이해가 가지 않았는데 map[0]=1 이라면 0행 1열에 퀸이 위치하는 것을 뜻합니다.
 * 즉, isPromising 함수에서 map[i]와 map[cur]이 같은지 비교하는 것은 같은 열에 위치하는지 체크하는 것을 뜻하며
 * 위에서 설명한 것처럼 대각성분도 체크해주어 현 상태가 유망한지 판단하는 것입니다. 행과 같은 경우는 dfs를 사용하기
 * 때문에 따로 체크를 하지 않고 유망할 경우 다음행을 탐색하는 방법으로 풀이하면 되는 문제입니다.
 * 처음 백트래킹 개념을 이해하지 못해서 직접 풀지는 못한 문제이지만 풀이를 보고 어느정도 백트래킹에대해 알 수 있었던
 * 문제였습니다.
 */
bool isPromising(int cur) {
    for(int i=0; i<cur; i++) {
        if(map[i] == map[cur] || abs(map[cur]-map[i]) == abs(cur-i))
            return false;
    }
    return true;
}
void solve(int cur) {
    if(cur==n)  result++;
    for(int i=0; i<n; i++) {
        map[cur] = i;
        if(isPromising(cur))    solve(cur+1);
    }
}
int main() {
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cin>>n;
    solve(0);
    cout<<result;
    return 0;
}