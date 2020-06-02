class Solution {
   
    public int solution(int[] stones, int k) {
        int answer = 0;
        
        // �ǳʶٴ� �ּ� �ο���
        int lowCount = 1;   
        
        // �ǳʶٴ� �ִ� �ο���
        int highCount = Integer.MAX_VALUE;  
        
        // �̺�Ž������ �̿��� �߰���
        int averageCount = (lowCount + highCount) / 2;  
        
        while (lowCount <= highCount) {
            averageCount = (lowCount + highCount) / 2;
            
            // �ǳʶ� ¡�˴ٸ� ��
            int jumpCount = 0;
            for (int i=0; i<stones.length; i++) {
                if (stones[i] - averageCount <= 0) {
                    jumpCount++;
                } else {
                    jumpCount = 0;
                }
                
                // k�� �̻� �ǳʶپ�� �ϴ°�� �ǳʶٴ� �ο����� ������ ���δ�
                if (jumpCount >= k) {    
                    highCount = averageCount - 1;
                    break;
                }
            }
            
            // �ǳʶ� ¡�˴ٸ� ������ k�� �̸��� ��� �ο����� �ø���.
            if (jumpCount < k) {
                lowCount = averageCount + 1;
                answer = lowCount;
            }  
        }

        return answer;
    }
}