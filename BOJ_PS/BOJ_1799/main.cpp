#include <iostream>
#include <algorithm>
#define MAX 10
using namespace std;
int n,result[2];
int map[MAX][MAX];
bool visit[2][2*MAX];
/**
 * O(2^(n*n))의 시간복잡도를 가지는데 n이 10인경우 2^100의 시간복잡도가 된다.
 * 때문에 N-Queen과 같이 행을 기준으로 모든 방법을 탐색하는 경우 시간초과가 된다.
 * 이 문제는 전체 탐색을 하면 안되는 문제이다. 여기서 풀이를 못했는데 다른 분들의 풀이를 보고
 * 독립사건으로 나누었습니다. 즉, 실제 체스판을 보면 흰색과 검정색이 교차로 있는데 비숍은 대각선만
 * 움직이기 때문에 처음 흰색칸에 존재한다면 흰색판안에서만 돌아다닐 수 있고
 * 검은색판에는 영향을 미치지 않습니다. 즉 흰색판과 검은색판은 비숍에 대해 독립적인 것이죠.
 * 이 문제를 나누어서 흰색판과 검은색판을 서로 나누어 결과를 더하면 각각 O(2^25)의 시간복잡도를 가지며
 * 이 값은 약 6~7천만 사이입니다. 비록 완전하게 풀지는 못한 문제이지만 새로운 풀이방법을 알게 된문제.
 * 시간초과가 나고 어떻게 분할해서 풀이할지 아이디어가 생각이 안났는데 아쉽다 ㅠㅠ
 */
void solve(int x, int y, int cnt, int color) {
    result[color]=max(result[color],cnt);
    if(x>=n)    return;
    if(y>=n) {
        x++;
        y=color^(x%2);
    }
    if(map[x][y] && !visit[0][x+y] && !visit[1][n-(x-y)]) {
        visit[0][x+y]=visit[1][n-(x-y)]=1;
        solve(x,y+2,cnt+1,color);
        visit[0][x+y]=visit[1][n-(x-y)]=0;
    }
    solve(x,y+2,cnt,color);
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cin>>n;
    for(int i=0; i<n; i++) {
        for(int j=0; j<n; j++) {
            cin>>map[i][j];
        }
    }
    solve(0,0,0,0);
    solve(0,1,0,1);
    cout<<result[0]+result[1];
    return 0;
}