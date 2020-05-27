class Solution {

    // #이 붙은 음을 소문자로 치환
    private String convertSound(String m) {
        m = m.replaceAll("C#", "c");
        m = m.replaceAll("D#", "d");
        m = m.replaceAll("F#", "f");
        m = m.replaceAll("G#", "g");
        m = m.replaceAll("A#", "a");
        
        return m;
    }
    
    // 곡의 재생시간을 분으로 환산
    private int getRunningTime(String startInfo, String endInfo) {
        int runningTime = 0;
        int startHour = Integer.parseInt(startInfo.split(":")[0]);
        int startMinute = Integer.parseInt(startInfo.split(":")[1]);
        int endHour = Integer.parseInt(endInfo.split(":")[0]);
        int endMinute = Integer.parseInt(endInfo.split(":")[1]);
        
        return (endHour - startHour) * 60 + (endMinute - startMinute);
    }
    
    // 재생 시간만큼 재생해 악보를 만듬
    private String playMusic(String sound, int runningTime) {
        StringBuilder sb = new StringBuilder();
        int soundLength = sound.length();
        for (int i=0; i<runningTime; i++) {
            sb.append(sound.charAt(i % soundLength));
        }
        return sb.toString();
    }
    
    public String solution(String m, String[] musicinfos) {
        String answer = "(None)";
        m = convertSound(m);
        
        int maxRunningTime = 0;
        for (String info : musicinfos) {
            String[] musicInfo = info.split(",");
            int runningTime = getRunningTime(musicInfo[0], musicInfo[1]);
            String musicName = musicInfo[2];
            String sound = convertSound(musicInfo[3]);
            
            // 곡 정보를 재생해서 만든 악보
            String music = playMusic(sound, runningTime);
            
            // 정보를 통해 만든 악보가 기억한 악보와 다르다면 제외
            if (!music.contains(m)) continue;
            
            // 악보가 같은경우 재생시간이 긴 제목을 반환
            if (runningTime > maxRunningTime) {
                answer = musicName;
                maxRunningTime = runningTime;
            }
        }
        return answer;
    }
}
