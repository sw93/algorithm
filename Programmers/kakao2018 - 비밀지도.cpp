// 문제출처
// https://programmers.co.kr/learn/courses/30/lessons/17681

#include <string>
#include <vector>
#include <algorithm>
using namespace std;
vector<string> solution(int n, vector<int> arr1, vector<int> arr2) {
    vector<string> answer;
    for (int i=0; i<n; i++) {
        int sumValue = (arr1[i] | arr2[i]);
        string ans = "";
        for (int j=0; j<n; j++) {
            if (sumValue & (1<<j)) ans+="#";
            else ans+=" ";
        }
        reverse(ans.begin(), ans.end());
        answer.push_back(ans);   
    }
    return answer;
}