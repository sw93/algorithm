#include <iostream>
#include <stack>
#include <string>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	/** 1. 문자열 풀이
	  * 폭탄문자열 끝과 결과값의 끝이 같다면 폭탄문자열이 포함되어 있는지 검사한다.
	  * 만약 포함되어 있다면 그 문자열의 길이만큼 결과값에서 지워주면 되는 문제.
	  * 중간에 포함되어 있어도 일단 끝문자를 첫 기준으로 삼기 때문에 연쇄적으로 폭발시킬 수 있다.
	  */
    string input, bomb, result;
    cin>>input>>bomb;
    int inputSize=input.size();
    int bombSize=bomb.size();
    for(int i=0; i<inputSize; i++) {
        result.push_back(input[i]);
        bool searchBomb = true;
        if(result.back() == bomb.back() && result.size() >= bombSize) {
            for(int j=0; j<bombSize; j++) {
                if(bomb[j] != result[result.size() -bombSize +j]) {
                    searchBomb = false;
                    break;
                }
            }
            if(searchBomb) {
                result.erase(result.size()-bombSize, bombSize);
            }
        }
    }
    if(result.empty())
        cout<<"FRULA";
    else
        cout<<result;
	
	/** 2. 스택으로 풀이
	 * 아이디어는 스택에 push할때 int값을 같이 push해줘서 int값이 폭탄 문자열 길이와 같다면 pop해주는 것이다.
	 * 먼저 stack에 input문자열을 push한다. 이때 문자열과 현재 문자열로부터 폭탄문자열과 몇번째로 같은지 같이 push한다.
	 * 예시를 들어 설명하면 AWSASWA가 input이고 폭탄 문자열이 SW라고 가정한다.
	 * 스택에는 다음과 같이 입력될 것이다.
	 * (A,0) / (W,0) / (S,1) / (A,0) / (S,1) / (W,2) / (A,0)
	 * 이 때 폭탄문자열의 길이가 2이므로 int값이 2일때 2개만큼 pop을 해준다.
	 */
	
	/* 소스코드
	string input, bomb;
    cin>>input>>bomb;
    stack<pair<char, int> > st;
    int inputSize=input.size();
    int bombSize=bomb.size();
    int sameBombCnt=0;
    for(int i=0; i<inputSize; i++) {
        if(input[i] == bomb[0]) sameBombCnt=1;
        else if(input[i] == bomb[sameBombCnt]) sameBombCnt++;
        else sameBombCnt=0;
        st.push(make_pair(input[i], sameBombCnt));
        if(bombSize == sameBombCnt) {
            for(int j=0; j<bombSize; j++)
                st.pop();
            if(!st.empty()) sameBombCnt=st.top().second;
            else sameBombCnt=0;
        }
    }
    if(st.empty()) cout<<"FRULA";
    else {
        char result[st.size()];
        result[st.size()]='\0';
        for(int i=st.size()-1; i>=0; i--) {
            result[i]=st.top().first;
            st.pop();
        }
        cout<<result;
    }
	*/
	return 0;
}
