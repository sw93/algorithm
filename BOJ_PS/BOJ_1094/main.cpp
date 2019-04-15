#include <iostream>
using namespace std;
/**
 *  초기 막대기의 길이는 64이며 길이가 x인 막대를 만드는 문제이다.
 *  stick 변수는 초기값을 가지고 있으면서 현재 자른 막대기의 길이를 가지는 변수입니다.
 *  x를 만드는 방식은 다음과 같다.
 *  1. 현재 막대기가 x보다 크다면 막대기를 반으로 자른다.
 *  2. 현재 막대기가 x보다 작거나 같다면 막대기를 붙인다.
 *     => 막대기를 붙였으므로 남은 x의 길이를 알기 위해 x를 막대기 길이만큼 빼줍니다.
 */
int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    int x, stick=64;
    cin>>x;
    int cnt=0;
    while(x>0) {
        if(stick > x) stick/=2;
        else {
            cnt++;
            x -= stick;
        }
    }
    cout<<cnt<<endl;
    return 0;
}