import java.util.*;
import java.util.regex.Matcher;
import java.util.regex.Pattern;

// * ���� . �� ġȯ
// Pattern matcher�� ����� �ش�Ǵ� �������� �Ǵ�
// �ش�ȴٸ� ���̵� ������ Ȯ���ϰ� �̹� �߰��� ���̵� �ƴ϶�� set�� �߰�
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
            
            // ���� ǥ���Ŀ� ��Ī�ǰ� ���̰� ������
            if (matcher.find() && user_id[i].length() == banned_id[index].length()) {
                
                // �̹� �湮�� ���� �ǳʶ�
                if ((visitBit & (1<<i)) == 1<<i) continue;
                dfs(user_id, banned_id, index+1, bannedIdSize+1, (visitBit | (1<<i)));
            }
        }
    }
}