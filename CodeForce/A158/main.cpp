#include <iostream>
#include <vector>
using namespace std;
// http://codeforces.com/problemset/problem/158/A
int main() {
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    int n,k,result=0;
    vector<int> scores;
    cin>>n>>k;
    int score;
    for(int i=0; i<n; i++) {
        cin>>score;
        scores.push_back(score);
    }
    for(int i=0; i<n; i++) {
        if(scores[i]>=scores[k-1] && scores[i]>0)   result++;
    }
    cout<<result<<endl;
    return 0;
}