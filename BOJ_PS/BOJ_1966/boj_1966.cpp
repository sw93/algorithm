#include <iostream>
#include <queue>
/*
* n�� 100�ۿ� ���� �ʱ� ������ O(n^2)�� ���⵵�� ������.
* �켱����ť�� �Ϲ�ť �ΰ����� ����ϰڽ��ϴ�.
*
* �켱����ť - �߿䵵�� �����ϸ� ���� ���� �߿䵵�� Ȯ��
* �Ϲ�ť	 - ���� ��ȣ�� �����ϸ� ������ ť�� ����
* 
* ���� �������� �߿䵵�� ���� ������ �����Ѵٸ�! ���� ������ ���� �߿����� �ʴٴ� ���Դϴ�.
* ���� �߿��� ������ Ȯ���� ���� �ְ����� ���� ���� �߿䵵�� ������ Ȯ���ϱ� ���� �켱����ť�� ����ϰڽ��ϴ�.
* ť front�� ��ġ�ϴ� ������ �߿䵵�� Ȯ���ϰ� �� ���� �켱����ť�� front��� ���� �߿��� ���� �ǰ�����.
* ���� �߿��� ������ ��� ť�� �켱���� ť���� ��� pop�ϰ� �׷��� ���� ����� ť�� front�� tail�� �����ϴ�.
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
