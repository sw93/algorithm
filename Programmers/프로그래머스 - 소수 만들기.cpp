#include <vector>
#include <cmath>
using namespace std;
int ans = 0;
bool checkPrime(int number) {
    if (number == 1) return false;
    if (number == 2) return true;
    for (int i=2; i<=sqrt(number); i++) {
        if (number % i == 0) {
            return false;
        }
    }
    return true;
}
void go(vector<int> nums, int startIdx, int depth, int sum) {
    if (depth == 3) {
        if (checkPrime(sum)) {
            ans++;
        }
        return;
    }
    for (int i=startIdx; i<nums.size(); i++) {
        go(nums, i+1, depth+1, sum+nums[i]);
    }
}
int solution(vector<int> nums) {
    go(nums, 0, 0, 0);
    
    return ans;
}