class Solution {

    // #�� ���� ���� �ҹ��ڷ� ġȯ
    private String convertSound(String m) {
        m = m.replaceAll("C#", "c");
        m = m.replaceAll("D#", "d");
        m = m.replaceAll("F#", "f");
        m = m.replaceAll("G#", "g");
        m = m.replaceAll("A#", "a");
        
        return m;
    }
    
    // ���� ����ð��� ������ ȯ��
    private int getRunningTime(String startInfo, String endInfo) {
        int runningTime = 0;
        int startHour = Integer.parseInt(startInfo.split(":")[0]);
        int startMinute = Integer.parseInt(startInfo.split(":")[1]);
        int endHour = Integer.parseInt(endInfo.split(":")[0]);
        int endMinute = Integer.parseInt(endInfo.split(":")[1]);
        
        return (endHour - startHour) * 60 + (endMinute - startMinute);
    }
    
    // ��� �ð���ŭ ����� �Ǻ��� ����
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
            
            // �� ������ ����ؼ� ���� �Ǻ�
            String music = playMusic(sound, runningTime);
            
            // ������ ���� ���� �Ǻ��� ����� �Ǻ��� �ٸ��ٸ� ����
            if (!music.contains(m)) continue;
            
            // �Ǻ��� ������� ����ð��� �� ������ ��ȯ
            if (runningTime > maxRunningTime) {
                answer = musicName;
                maxRunningTime = runningTime;
            }
        }
        return answer;
    }
}
