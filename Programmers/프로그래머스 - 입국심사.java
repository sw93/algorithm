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
            
            // �ɻ� ������ �ο� = �ð� / �ɻ��ϴµ� �ɸ��� �ð�
            for (int i=0; i<times.length; i++) {
                count += mid / times[i];
            }
            
            // mid �ð����� �ɻ��� �ο��� n���� ���� ��� �ð��� �� �ʿ�
            if (count < n) {
                left = mid + 1;
            } else { // �ɻ��� �ο��� n�� �̻��� ��� �ð��� �ٿ��� ��
                right = mid - 1;
                answer = mid;
            }
        }
        
        return answer;
    }
}