#include <string>
#include <vector>
#include <stack>
using namespace std;

// 올바른 괄호 문자열 체크
bool isCorrectBracket(string bracket) {
    stack<char> st;
    for (int i=0; i<bracket.size(); i++) {
        if (bracket[i] == '(') {
            st.push(bracket[i]);
        } else if (bracket[i] == ')') {
            if (st.empty()) {
                return false;
            } else {
                st.pop();
            }
        }
    }
    
    if (st.empty()) return true;
    else return false;
}

// 재귀
string go(string p) {
    // 1번
    if (p == "") {
        return p;
    }
    
    // 2번
    string u = "", v = "";
    int left = 0, right = 0;
    for (int i=0; i<p.size(); i++) {
        if (p[i] == '(') left++;
        else if (p[i] == ')') right++;
        if (left == right) {
            u = p.substr(0, i + 1);
            v = p.substr(i + 1);
            break;
        }
    }
    
    // 3번
    if (isCorrectBracket(u)) {
        return u + go(v);
    } else {    // 4번
        string ret = "(" + go(v) + ")";
        u = u.substr(1, u.size() - 2);
        for (int i=0; i<u.size(); i++) {
            if (u[i] == '(') u[i] = ')';
            else if (u[i] == ')') u[i] = '(';
        }
        return ret + u;
    }
}

string solution(string p) {
    string answer = "";
    if (isCorrectBracket(p)) return p;
    answer = go(p);
    return answer;
}