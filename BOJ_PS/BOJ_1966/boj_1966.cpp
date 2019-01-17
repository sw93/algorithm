#include <iostream>
#include <queue>
/*
* n이 100밖에 되지 않기 때문에 O(n^2)의 복잡도를 가진다.
* 우선순위큐와 일반큐 두가지를 사용하겠습니다.
*
* 우선순위큐 - 중요도를 저장하며 가장 높은 중요도를 확인
* 일반큐	 - 문서 번호를 저장하며 프린터 큐를 구현
* 
* 현재 문서보다 중요도가 높은 문서가 존재한다면! 현재 문서가 가장 중요하지 않다는 말입니다.
* 가장 중요한 것인지 확인할 수는 있겠지만 가장 높은 중요도를 빠르게 확인하기 위해 우선순위큐를 사용하겠습니다.
* 큐 front에 위치하는 문서의 중요도를 확인하고 그 값이 우선순위큐의 front라면 가장 중요한 것이 되겠지요.
* 가장 중요한 문서일 경우 큐와 우선순위 큐에서 모두 pop하고 그렇지 않은 경우라면 큐의 front를 tail로 보냅니다.
*/
using namespace std;

int main(void) {
	ios_base::sync_with_stdio(false);	cin.tie(0);
	int tc, n, m;
	cin >> tc;
	while (tc--) {
		int result = 0;
		queue<pair<int, int> > q;
		priority_queue<int> pq;
		cin >> n >> m;
		int priority;
		for (int i = 0; i < n; i++) {
			cin >> priority;
			q.push(make_pair(priority, i));
			pq.push(priority);
		}

		while (!q.empty()) {
			int prior = q.front().first;
			int num = q.front().second;
			q.pop();
			if (pq.top() == prior) {
				result++;
				pq.pop();
				if (num == m)
					break;
			}
			else q.push(make_pair(prior, num));
		}
		cout << result << endl;
	}

	return 0;
}
