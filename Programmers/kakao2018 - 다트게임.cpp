#include <string>
#include <cmath>
#include <vector>
using namespace std;
int solution(string dartResult) {
    int answer = 0, index = -1;
    vector<int> score;
    for (int i=0; i<dartResult.size(); i++) {
        if (dartResult[i] == 'S') {
        } else if (dartResult[i] == 'D') {
            score[index] = pow(score[index], 2);
        } else if (dartResult[i] == 'T') {
            score[index] = pow(score[index], 3);
        } else if (dartResult[i] == '*') {
            score[index] *= 2;
            if (index > 0) score[index-1] *= 2;
        } else if (dartResult[i] == '#') {
            score[index] *= -1;
        } else {
            index++;
            if (i+1 < dartResult.size() && dartResult[i+1] == '0') {
                score.push_back(10);
                i++;
            } else {
                score.push_back(dartResult[i] - 48);
            }
        }
    }
    for (int i=0; i<score.size(); i++) answer+=score[i];
    return answer;
}