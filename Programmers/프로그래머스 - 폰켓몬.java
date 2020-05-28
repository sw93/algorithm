import java.util.*;
class Solution {
    public int solution(int[] nums) {
        Set<Integer> phoneketmonSet = new HashSet<>();
        int pickSize = nums.length / 2;
        for (int num : nums) {
            phoneketmonSet.add(num);
        }
        
        return pickSize > phoneketmonSet.size() 
                    ? phoneketmonSet.size() : pickSize;
    }
}