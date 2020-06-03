class Solution {
    private static int dy[] = { 0, 1, 0, -1 };
    private static int dx[] = { 1, 0, -1, 0 };
    private static boolean visit[][][][] = new boolean[11][11][11][11];
    
    public int solution(String dirs) {
        int answer = 0;
        int y = 5;
        int x = 5;
        
        int dirIndex = 0;
        for (int i=0; i<dirs.length(); i++) {
            char dir = dirs.charAt(i);
            if (dir == 'U') {
                dirIndex = 3;
            } else if (dir == 'D') {
                dirIndex = 1;
            } else if (dir == 'R') {
                dirIndex = 0;
            } else if (dir == 'L') {
                dirIndex = 2;
            }
            
            int ny = y + dy[dirIndex];
            int nx = x + dx[dirIndex];
            
            // 지도를 벗어난 경우는 제외
            if (ny<0 || nx<0 || ny>=11 || nx>=11) continue;
            
            // (y,x) => (ny, nx)로 가는 길을 처음 걸을때
            if (!visit[y][x][ny][nx] == true && !visit[ny][nx][y][x] == true) {
                visit[y][x][ny][nx] = true;
                visit[ny][nx][y][x] = true;   
                answer++;            
            }
            
            // 현재 좌표 갱신
            y = ny;
            x = nx;
        }
        return answer;
    }
}