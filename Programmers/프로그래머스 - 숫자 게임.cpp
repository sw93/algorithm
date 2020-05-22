#include <string>
#include <vector>
#include <algorithm>
using namespace std;

int solution(vector<int> A, vector<int> B) {
    int answer = 0;
    sort(A.begin(), A.end());
    sort(B.begin(), B.end());
    
    int aIdx = A.size()-1;
    int bIdx = B.size()-1;
    while (1) {
        if (aIdx < 0) break;
        if (A[aIdx] < B[bIdx]) {
            bIdx--;
            answer++;
        }
        aIdx--;
    }
    
    return answer;
}