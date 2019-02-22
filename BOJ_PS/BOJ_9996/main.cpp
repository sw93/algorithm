#include <iostream>
#include <string>
using namespace std;
const string yes="DA\n", no="NE\n";
/**
 * 패턴의 형식이 접두사 *  접미사 형태인데 이것을 이용하면 된다.
 * find함수로 '*'의 위치를 찾아내서 접두사 접미사를 구한다. 처음에는 오직 접두사 접미사만 같으면
 * 되는줄 알았으나 생각해보니 예외 케이스가 있었다. 패턴이 swj*jsw 이고 파일이름이 swjsw인 경우이다.
 * 이를 해결하기 위해 먼저 파일의 길이와 패턴길이를 판별한뒤 접두사와 접미사가 같은지 판별하였다.
 * 생각보다 흥미로웠던 문제
 */
int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    int n, suffixSize;
    string pattern, fileName, prefix, suffix;
    cin>>n>>pattern;

    int asterikIdx = pattern.find('*');
    prefix=pattern.substr(0,asterikIdx);
    suffix=pattern.substr(asterikIdx+1);
    suffixSize=suffix.size();

    while(n--) {
        cin>>fileName;
        if(fileName.size() < pattern.size()-1) {
            cout<<no;
            continue;
        }
        else if(fileName.size() == pattern.size()-1) {
            if(fileName == pattern.substr(0, asterikIdx) + pattern.substr(asterikIdx+1))
                cout<<yes;
            else cout<<no;
            continue;
        }
        else {
            string prefixFileName = fileName.substr(0, asterikIdx);
            string suffixFileName = fileName.substr(fileName.size()-suffixSize);
            if(prefix==prefixFileName && suffix==suffixFileName)
                cout<<yes;
            else
                cout<<no;
            continue;
        }
    }
    return 0;
}