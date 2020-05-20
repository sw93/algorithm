#include <string>
#include <vector>
#include <stack>
using namespace std;

// �ùٸ� ��ȣ ���ڿ� üũ
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

// ���
string go(string p) {
    // 1��
    if (p == "") {
        return p;
    }
    
    // 2��
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
    
    // 3��
    if (isCorrectBracket(u)) {
        return u + go(v);
    } else {    // 4��
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