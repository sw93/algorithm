import java.io.BufferedReader;
import java.io.InputStreamReader;
 
/**
 * DP문제이다. N이 10^6까지 범위가 주어지기 때문에 전체탐색을 힘들것이라 판단되었다.
 * DP문제에서 가장중요한 점화식은 조금만 생각하면 유추해 낼 수 있다.
 * 연산의 최소값을 출력하기 때문에 일반적으로 n번 연산한 횟수는 n-1번 연산의 최솟값 +1임을 의미한다.
 * 이를 점화식으로 나타내면
 * case 1)
 * dp[n] = min(dp[n/3] + 1, dp[n-1] + 1)
 * case 2)
 * dp[n] = min(dp[n/2] + 1, dp[n-1] + 1)
 * case 3)
 * dp[n] = dp[n-1] + 1
 *
 */
 
public class Main {
    public static final int MAX = 1000001;
    public static void main(String[] args) throws Exception {
        int n;
        int[] dp = new int[MAX];
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        n=Integer.parseInt(br.readLine());
 
        // 1일때는 연산횟수가 없다.
        dp[1]=0;
        for(int i=2; i<=n; i++) {
            if(i%3==0)
                dp[i]=Math.min(dp[i/3]+1, dp[i-1]+1);
            else if(i%2==0)
                dp[i]=Math.min(dp[i/2]+1, dp[i-1]+1);
            else
                dp[i]=dp[i-1]+1;
        }
 
        System.out.println(dp[n]);
 
    }
}
