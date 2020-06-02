class Solution {
   
    public int solution(int[] stones, int k) {
        int answer = 0;
        
        // 건너뛰는 최소 인원수
        int lowCount = 1;   
        
        // 건너뛰는 최대 인원수
        int highCount = Integer.MAX_VALUE;  
        
        // 이분탐색에서 이용할 중간값
        int averageCount = (lowCount + highCount) / 2;  
        
        while (lowCount <= highCount) {
            averageCount = (lowCount + highCount) / 2;
            
            // 건너뛴 징검다리 수
            int jumpCount = 0;
            for (int i=0; i<stones.length; i++) {
                if (stones[i] - averageCount <= 0) {
                    jumpCount++;
                } else {
                    jumpCount = 0;
                }
                
                // k개 이상 건너뛰어야 하는경우 건너뛰는 인원수를 반으로 줄인다
                if (jumpCount >= k) {    
                    highCount = averageCount - 1;
                    break;
                }
            }
            
            // 건너뛴 징검다리 개수가 k개 미만인 경우 인원수를 늘린다.
            if (jumpCount < k) {
                lowCount = averageCount + 1;
                answer = lowCount;
            }  
        }

        return answer;
    }
}