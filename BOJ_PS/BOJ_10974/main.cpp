#include <iostream>
#include <vector>
using namespace std;
vector<bool> visit;
vector<int> permutation;
/**
 * 재귀적으로 풀이하였음. visit을 이용해서 같은 숫자가 반복출력되지 않도록 해야한다.
 * printPermutation에서 number는 순열에 추가될 숫자 digit은 순열의 현재 자릿수, n은 입력받은 n을 뜻한다.
 * 아래 main for문에서는 첫번째 숫자를 선택해주고 printPermutation의 for문을 통해 n자리수 순열을 만들어
 * 출력해주면 되는 문제이다.
 */
void printPermutation(int number, int digit, int n) {
    permutation[digit]=number;
    if(digit==n) {
        for(int i=1; i<=n; i++) cout<<permutation[i]<<" ";
        cout<<"\n";
        return;
    }
    for(int i=1; i<=n; i++) {
        if(visit[i]) continue;
        visit[i]=1;
        printPermutation(i, digit+1, n);
        visit[i]=0;
    }
}
int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    int n;
    cin>>n;
    visit.resize(n+1); permutation.resize(n+1);
    for(int i=1; i<=n; i++) {
        visit[i]=1;
        printPermutation(i, 1, n);
        visit[i]=0;
    }
    return 0;
}