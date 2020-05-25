#include <string>
#include <vector>
#include <algorithm>
using namespace std;
vector<bool> visit;
vector<string> path;
vector<vector<string>> answer;
void getTravelPath(vector<vector<string>> &tickets, string from, int depth) {
	if (tickets.size() == depth) {
		answer.push_back(path);
		return;
	}

	for (int i=0; i<tickets.size(); i++) {
		if (visit[i] || from != tickets[i][0]) continue;
		visit[i] = 1;
		path.push_back(tickets[i][1]);
		getTravelPath(tickets, tickets[i][1], depth+1);
		path.pop_back();
		visit[i] = 0;
	}
}
vector<string> solution(vector<vector<string>> tickets) {
    visit.resize(tickets.size(), 0);
    path.push_back("ICN");
    getTravelPath(tickets, "ICN", 0);
    sort(answer.begin(), answer.end());
    return answer.front();
}