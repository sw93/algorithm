import java.io.BufferedReader;
import java.io.InputStreamReader;

public class Main {
    public static int n;
    public static int[] num;
    public static int[] result;

    public static void main(String[] args) throws Exception {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        while(true) {
            n=br.read();
            if(n==0)
                break;
            for(int i=0; i<n; i++) {
                num[i]=br.read();
            }
            solve(0,0);
        }
    }

    public static void solve(int s, int depth) {
        if(depth==6) {
            for(int i=0; i<depth; i++)
                System.out.print(result[i]+" ");

            return;
        }
        for(int i=s; i<n; i++) {
            result[depth]=num[i];
            solve(s+1, depth+1);
        }
    }
}
