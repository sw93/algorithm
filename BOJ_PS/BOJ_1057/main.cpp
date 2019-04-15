#include <iostream>
using namespace std;
/**
 * 다음라운드의 자신의 번호 = (현재 자신의 번호 + 1) / 2
 * ==> int형 기준
 * 다음라운드의 번호가 같다면 break해준다.
 * Ex) 7, 8 번 매칭이라면 (7+1)/2 = 8,  (8+1)/2 = 8 이므로 1라운드에 매칭하는 것
 */
int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    int n, kim, lim;
    cin>>n>>kim>>lim;
    int round=1;
    while(n) {
        if((kim+1)/2 == (lim+1)/2) break;
        kim = (kim+1)/2;
        lim = (lim+1)/2;
        round++;
        n/=2;
    }
    if(!n) round=-1;
    cout<<round<<"\n";
    return 0;
}