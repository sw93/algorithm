import java.util.Arrays;
class Solution {
    public long solution(int n, int[] times) {
        long answer = 0;
        Arrays.sort(times);
        
        long left = 1;
        long right = (long)n * times[times.length - 1];
        while (left <= right) {
            long mid = (left + right) / 2;
            long count = 0;
            
            // 심사 가능한 인원 = 시간 / 심사하는데 걸리는 시간
            for (int i=0; i<times.length; i++) {
                count += mid / times[i];
            }
            
            // mid 시간동안 심사한 인원이 n명보다 적은 경우 시간이 더 필요
            if (count < n) {
                left = mid + 1;
            } else { // 심사한 인원이 n명 이상인 경우 시간을 줄여도 됨
                right = mid - 1;
                answer = mid;
            }
        }
        
        return answer;
    }
}