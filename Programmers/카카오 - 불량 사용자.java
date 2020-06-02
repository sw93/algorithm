import java.util.*;
import java.util.regex.Matcher;
import java.util.regex.Pattern;

// * 문자 . 로 치환
// Pattern matcher를 사용해 해당되는 문자인지 판단
// 해당된다면 길이도 같은지 확인하고 이미 추가한 아이디가 아니라면 set에 추가
class Solution {
    private static HashSet<Integer> set;
    public int solution(String[] user_id, String[] banned_id) {
        set = new HashSet<>();
        dfs(user_id, banned_id, 0, 0, 0);
        return set.size();
    }
    
    private static void dfs(String[] user_id, String[] banned_id, int index, int bannedIdSize, int visitBit) {
        if (bannedIdSize == banned_id.length) {
            set.add(visitBit);
            return;
        }
        
        for (int i=0; i<user_id.length; i++) {
            String changeBannedId = banned_id[index].replace("*", ".");
            Pattern pattern = Pattern.compile(changeBannedId);
            Matcher matcher = pattern.matcher(user_id[i]);
            
            // 정규 표현식에 매칭되고 길이가 같으면
            if (matcher.find() && user_id[i].length() == banned_id[index].length()) {
                
                // 이미 방문한 것은 건너뜀
                if ((visitBit & (1<<i)) == 1<<i) continue;
                dfs(user_id, banned_id, index+1, bannedIdSize+1, (visitBit | (1<<i)));
            }
        }
    }
}