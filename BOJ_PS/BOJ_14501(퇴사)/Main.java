import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.util.Arrays;
import java.util.StringTokenizer;

public class Main {

    public static final int INF = 0x7fffffff;
    public static final int MAX =16;
    public static int[] t = new int[MAX];
    public static int[] p = new int[MAX];
    public static int[] dp = new int[MAX];
    public static int n;

    public static void main(String[] args) throws Exception {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        n = Integer.parseInt(br.readLine());
        // input data...
        for (int i = 0; i <n; i++) {
            StringTokenizer st = new StringTokenizer(br.readLine());

            t[i] = Integer.parseInt(st.nextToken());
            p[i] = Integer.parseInt(st.nextToken());
        }
        Arrays.fill(dp, -1);
        int ret=solve(0);
        System.out.println(ret);
    }

    public static int solve(int s) {
        if(s==n)
            return 0;
        if(s>n)
            return -INF;

        int ret=dp[s];
        if(ret!=-1)
            return ret;

        ret=Math.max(solve(s+1), solve(s+t[s]) + p[s]);
        return ret;
    }
}

/**
 * day   1   2   3   4   5   6   7
 * =====================================
 *   t   3   5   1   1   2   4   2
 *   p   10  20  10  20  15  40  200
 *
 *  i에서 시작해서 퇴사일 까지 최대 값을 dp[i]에 저장합니다.
 *  dp[i]는 두가지 중 최대값을 저장하면 된다. (i == 일)
 *    1) 오늘의 스케쥴을 하는 경우 : dp[i + t[i]] + p[i]
 *    2) 오늘의 스케쥴을 안 하는 경우 : dp[i+1]
 /*
 *  즉 solve(0) = Math.max(solve(1), solve(0 + t[0]) + p[0])
 *  .
 *  .
 *  .
 *  .
 *  .
 *    solve(6) = Math.max(solve(7), solve(8)+200
 *
 *    과 같이 나열된다. 하지만 여기서 7일까지만 일하므로 8일차는 범위를 벗어난 경우이다.
 *    때문에 -값을 주어 max에 영향을 주지 않도록 조치한다.
 *    이 재귀를 풀어서 역으로 추적하면 쉽게 답을 구할 수 있다.
 */
