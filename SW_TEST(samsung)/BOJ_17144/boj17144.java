import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.util.ArrayList;
import java.util.StringTokenizer;

public class Main {
    private static int r, c, t;
    private static int dy[] = {0, -1, 0, 1};
    private static int dx[] = {1, 0, -1, 0};
    private static int map[][];
    private static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    private static StringTokenizer st;
    private static ArrayList<Integer> cleaner;

    public static void main(String[] args) throws Exception {
        init();
        while (true) {
            t--;
            spreadDust();
            activateAirCleaner();

            if (t == 0) {
                System.out.println(countDustVolumn());
                break;
            }
        }
    }

    private static int countDustVolumn() {
        int ret = 0;
        for (int y=0; y<r; y++) {
            for (int x=0; x<c; x++) {
                if (map[y][x] != 0 && map[y][x] != -1) ret += map[y][x];
            }
        }
        return ret;
    }

    private static void copyMap(int src[][], int dest[][]) {
        for (int y=0; y<r; y++) {
            for (int x=0; x<c; x++) {
                dest[y][x] = src[y][x];
            }
        }
    }

    private static void activateAirCleaner() {
        int upY = cleaner.get(0);
        int downY = cleaner.get(1);

        // 위쪽
        for (int y=upY-1; y>0; y--) {
            map[y][0] = map[y-1][0];
        }
        for (int x=0; x<c-1; x++) {
            map[0][x] = map[0][x+1];
        }
        for (int y=0; y<upY; y++) {
            map[y][c-1] = map[y+1][c-1];
        }
        for (int x=c-1; x>0; x--) {
            map[upY][x] = map[upY][x-1];
        }
        map[upY][1] = 0;

        // 아래쪽
        for (int y=downY+1; y<r-1; y++) {
            map[y][0] = map[y+1][0];
        }
        for (int x=0; x<c-1; x++) {
            map[r-1][x] = map[r-1][x+1];
        }
        for (int y=r-1; y>=downY; y--) {
            map[y][c-1] = map[y-1][c-1];
        }
        for (int x=c-1; x>1; x--) {
            map[downY][x] = map[downY][x-1];
        }
        map[downY][1] = 0;
    }

    private static void spreadDust() {
        int tempMap[][] = new int[r][c];
        copyMap(map, tempMap);

        for (int y=0; y<r; y++) {
            for (int x=0; x<c; x++) {
                if (map[y][x] != 0 && map[y][x] != -1) {
                    int count = 0;
                    int dust = map[y][x] / 5;
                    for (int i=0; i<4; i++) {
                        int ny = y+dy[i];
                        int nx = x+dx[i];

                        if (ny<0 || nx<0 || ny>=r || nx>=c || map[ny][nx] == -1) continue;
                        tempMap[ny][nx] += dust;
                        count++;
                    }
                    tempMap[y][x] -= (count * dust);
                }
            }
        }
        copyMap(tempMap, map);
    }

    private static void init() throws Exception {
        st = new StringTokenizer(br.readLine());
        r = Integer.parseInt(st.nextToken());
        c = Integer.parseInt(st.nextToken());
        t = Integer.parseInt(st.nextToken());
        map = new int[r][c];
        cleaner = new ArrayList<>();

        for (int y=0; y<r; y++) {
            st = new StringTokenizer(br.readLine(), " ");
            for (int x=0; x<c; x++) {
                map[y][x] = Integer.parseInt(st.nextToken());
                if (map[y][x] == -1) cleaner.add(y);
            }
        }
    }
}