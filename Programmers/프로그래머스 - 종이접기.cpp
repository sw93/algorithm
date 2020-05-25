#include <string>
#include <vector>

using namespace std;
/*
* 규칙 
* n = 1 -> 0
* n = 2 -> 0 0 1
* n = 3 -> 0 0 1 0 0 1 1
* n = 4 -> 0 0 1 0 0 1 1 0 0 0 1 1 0 1 1
* n = 2 -> 3이 될때 0 0 1과 0 1 1 을 보면 기존 0은 1로 1은 0으로 바뀌고 가운데 0이 끼는 것을 알 수 있음
* n = 3 -> 4가 될때도 기존 3인 값에 0이 추가 되고 역순으로 0은 1로 1은 0으로 바뀜
*/
vector<int> solution(int n) {
    vector<int> answer;
    answer.push_back(0);
    if (n == 1) return answer;
    for (int i=2; i<=n; i++) {
        vector<int> temp = answer;
        answer.push_back(0);
        for (int j=temp.size()-1; j>=0; j--) {
            if (temp[j] == 0) answer.push_back(1);
            else if (temp[j] == 1) answer.push_back(0);
        }
    }
    
    return answer;
}