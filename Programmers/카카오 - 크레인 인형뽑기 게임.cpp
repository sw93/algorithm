#include <string>
#include <vector>
#include <stack>
using namespace std;

int solution(vector<vector<int>> board, vector<int> moves) {
    int answer = 0;
    stack<int> s;
    for (int i=0; i<moves.size(); i++) {
        int x = moves[i] - 1;
        
        for (int y=0; y<board.size(); y++) {
            if (board[y][x] == 0) continue;

            if (!s.empty() && (s.top() == board[y][x])) {
                s.pop();
                answer += 2;
            } else {
                s.push(board[y][x]);
            }
            
            board[y][x] = 0;
            break;
        }
    }
    return answer;
}