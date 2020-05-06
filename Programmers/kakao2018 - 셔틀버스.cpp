#include <string>
#include <vector>
#include <algorithm>
using namespace std;
const int START_BUS_MINUTE = 9 * 60;
const int LAST_BUS_MINUTE = 24 * 60;
int getIntMinute(string time) {
    int ret = ((time[0]-'0')*10 + (time[1]-'0')) * 60;
    ret += (time[3]-'0')*10 + (time[4]-'0');
    return ret;
}
string getStringTime(int time) {
    string ret = to_string((time/600));
    ret += to_string((time/60)%10);
    ret +=  ':';
    ret += to_string((time%60)/10);
    ret += to_string((time%60)%10);
    return ret;
}
string solution(int n, int t, int m, vector<string> timetable) {
    string ret = "";
    vector<int> v;
    for (int i=0; i<timetable.size(); i++) v.push_back(getIntMinute(timetable[i]));
    sort(v.begin(), v.end());
    
    int boardCount = 0;
    int startTime = START_BUS_MINUTE;
    for (int i=0; i<n; i++) {

        // 문제 조건 23:59까지만 가능
    	if (startTime > LAST_BUS_MINUTE) break;
    	int maxBoardCount = m;
        
    	for (int j=boardCount; j<v.size(); j++) {
    		if (maxBoardCount == 0 || v[j] > startTime) break;
            boardCount++;
            maxBoardCount--;
    	}

        // 마지막 버스
    	if (i == n-1) {
            
          // 탑승할 자리가 없는 경우 1분 일찍 나옴
          if (maxBoardCount == 0) startTime = v[boardCount-1] - 1;  
    	}  else startTime += t;
    }
    ret = getStringTime(startTime);
    return ret;
}