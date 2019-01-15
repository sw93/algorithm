import java.io.BufferedReader;
import java.io.InputStreamReader;

public class Main {
    public static int t, n;
    public static int[] dp;
    public static void main(String[] args) throws Exception {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        t=Integer.parseInt(br.readLine());
        dp=new int[11];
        dp[1]=1;
        dp[2]=2;
        dp[3]=4;
        
        for(int i=0; i<t; i++) {
            n=Integer.parseInt(br.readLine());
            for(int j=4; j<=n; j++) {
                dp[j]=dp[j-1]+dp[j-2]+dp[j-3];
            }
        }
        
        System.out.println(dp[n]);
    }
}
