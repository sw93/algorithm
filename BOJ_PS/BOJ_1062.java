import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.util.StringTokenizer;

public class BOJ1062 {
    private static int n, k, ans;
    private static String[] words = new String[51];
    private static boolean[] visit = new boolean[26];
    private static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    private static StringTokenizer st;

    private static void init() throws Exception {
        st = new StringTokenizer(br.readLine());
        n = Integer.parseInt(st.nextToken());
        k = Integer.parseInt(st.nextToken());

        for (int i=0; i<n; i++) {
            st = new StringTokenizer(br.readLine());
            String word = st.nextToken();

            // a n t i c 필수
            word = word.replaceAll("a" , "");
            word = word.replaceAll("n" , "");
            word = word.replaceAll("t" , "");
            word = word.replaceAll("i" , "");
            word = word.replaceAll("c" , "");
            words[i] = word;
        }
        visit['a'-'a'] = true;
        visit['n'-'a'] = true;
        visit['t'-'a'] = true;
        visit['i'-'a'] = true;
        visit['c'-'a'] = true;

    }
    private static void checkString() {
        int count = 0;

        for (int i=0; i<n; i++) {
            boolean isRead = true;
            for (int j=0; j<words[i].length(); j++) {
                if (!visit[words[i].charAt(j) - 'a']) {
                    isRead = false;
                    break;
                }
            }

            if (isRead) {
                count++;
            }
        }
        ans = Math.max(ans, count);
    }

    private static void dfs(int index, int depth) {
        if (depth == k) {
            checkString();
            return;
        }

        for (int i=index; i<26; i++) {
            if (visit[i]) continue;

            visit[i] = true;
            dfs(i, depth+1);
            visit[i] = false;
        }
    }

    public static void main(String[] args) throws Exception {
        init();
        // a n t i c 필수
        if (k < 5) {
            System.out.println(0);
            return;
        } else if (k == 26) {
            System.out.println(n);
            return;
        }
        k -= 5;
        dfs(0, 0);
        System.out.println(ans);
    }
}
