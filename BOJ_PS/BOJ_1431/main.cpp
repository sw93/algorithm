#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;
/**
 * 단순 문제대로 구현하면 되는 문제이다.
 * 다만 주의할 점은 1번 2번 조건이 부합하지 않는 경우에만
 * 3번조건으로 정렬한다는 것이다. 처음에 c++로 채점을 해서 계속 틀렸는데
 * c++14로 하니 맞았다 왜인지는 모르겠지만 ide도 c++14를 사용해서 앞으로는
 * c++14로 제출해야겠다...
 */
int sum(const string &a) {
    int ret=0;
    for(int i=0; i<a.length(); i++) {
        if((a[i]-'0')>=1 && (a[i]-'0')<=9)
            ret += a[i]-'0';
    }
    return ret;
}
bool comp(const string &a, const string &b) {
    if(a.size() != b.size())
        return a.size() < b.size();
    else {
        int asize=sum(a);
        int bsize=sum(b);
        if(asize != bsize) {
            return asize<bsize;
        } else {
            return a<b;
        }
    }
}
int main(int argc, const char * argv[]) {
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    int n; cin>>n;
    vector<string> vec_str(n);
    for(int i=0; i<n; i++) cin>>vec_str[i];
    sort(vec_str.begin(), vec_str.end(), comp);
    for(int i=0; i<n; i++) cout<<vec_str[i]<<"\n";
    return 0;
}
