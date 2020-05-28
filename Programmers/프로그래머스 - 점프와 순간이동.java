import java.util.*;
/**
* k칸 앞으로 점프 || 현재까지 온거리 * 2
* k칸 점프시 건전지 사용
* n만큼 떨어져 있는 곳으로 이동할 때 건전지 사용량을 최소로하는 값 return
* top - down 방식으로 풀이
*/
public class Solution {
    public int solution(int n) {
        int ans=0;
        while (n > 0) {
            if (n % 2 == 0) {
                n /= 2;
            } else {
                ans++;
                n -= 1;
            }
        }
        return ans;
    }
}