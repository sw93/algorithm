import java.util.*;
class Solution {
    // n명 
    // i % n 값에 +1 한게 사람순서
    // i / n 값에 +1 한게 차례
    // 끝글자랑 다음의 처음글자 확인
    public int[] solution(int n, String[] words) {
        int[] answer = {0, 0};
        Set<String> historySet = new HashSet<>();
        historySet.add(words[0]);
        char prevCharacter = words[0].charAt(words[0].length() - 1);
        
        for (int i=1; i<words.length; i++) {
            historySet.add(words[i]);
            if (!words[i].startsWith(Character.toString(prevCharacter)) || historySet.size() != i+1) {
                answer[0] = (i%n)+1;
                answer[1] = (i/n)+1;
                break;
            }
            prevCharacter = words[i].charAt(words[i].length() - 1);
        }
        return answer;
    }
}