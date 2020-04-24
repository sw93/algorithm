import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.util.StringTokenizer;

public class Main {
    private static int n, m, ans=0;
    private static int dy[] = {0, -1, 0, 1};
    private static int dx[] = {1, 0, -1, 0};
    private static int map[][];
    private static boolean visit[][];

    public static void main(String[] args) throws Exception {
        init();
        for (int y=0; y<n; y++) {
            for (int x=0; x<m; x++) {
                dfs(y, x, 0, 0);
                checkException(y, x);
            }
        }
        System.out.println(ans);
    }

    private static void dfs(int y, int x, int sum, int count) {
        if (count == 4) {
            ans = Math.max(ans, sum);
            return;
        }

        for (int i=0; i<4; i++) {
            int ny = y+dy[i];
            int nx = x+dx[i];
            if (ny<0 || nx<0 || ny>=n || nx>=m || visit[ny][nx]) continue;
            visit[ny][nx] = true;
            dfs(ny, nx, sum+map[ny][nx], count+1);
            visit[ny][nx] = false;
        }
    }

    private static void checkException(int y, int x) {
        int sum = map[y][x];
        int count = 1;
        int min = 987654321;

        for (int i=0; i<4; i++) {
            int ny = y+dy[i];
            int nx = x+dx[i];
            if (ny<0 || nx<0 || ny>=n || nx>=m) continue;
            sum += map[ny][nx];
            min = Math.min(min, map[ny][nx]);
            count++;
        }

        if (count == 5) {
            sum -= min;
        }
        ans = Math.max(ans, sum);
    }

    private static void init() throws Exception {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine());
        n = Integer.parseInt(st.nextToken());
        m = Integer.parseInt(st.nextToken());
        map = new int[n][m];
        visit = new boolean[n][m];

        for (int y = 0; y < n; y++) {
            st = new StringTokenizer(br.readLine());
            for (int x = 0; x < m; x++) {
                map[y][x] = Integer.parseInt(st.nextToken());
            }
        }
    }
}