#define  _CRT_SECURE_NO_WARNINGS
#include <cstdio>
#include <vector>
#include <algorithm>
#define MAX 51
#define INF 0x7fffffff

using namespace std;

int n, m, result;
int map[MAX][MAX];
vector<pair<int, int> > house, chicken, selected;
/*
 * �ð����⵵�� ������� ���ϰڴ�. �ִ� 13���� ġŲ������ �ִ� 13���� ���� ���ε� 
 * ������ ����� �����Ƿ� �־��� ��� 13C6 �ϰŶ� �����ȴ�. ������ 1�ʶ�� ���ѽð� ���� ��üŽ������
 * Ǯ���� �� �ִٰ� �����Ǿ� dfs�� Ǯ���Ͽ����ϴ�. (Ȥ�� �ð����⵵ �ƽô� ���� ��� ��Ź�帳�ϴ� �̤�)
 * 
 * ������ ������ ���� map�� �Է¹��� �� ���� ġŲ���� ��ǥ�� ���� �����߽��ϴ�.
 * ���� dfs�� ���� ġŲ���� ������ ������� �����ϰ� selected ���Ϳ� �����մϴ�. 
 * �� selected������ ����� m�ΰ�� �������� �־��� �ִ� ġŲ���� �����̹Ƿ�
 * ���� ġŲ���� �Ÿ��� ����ؼ� �ּҰ��� �������ִ� �����Դϴ�.
 * 
 * ���⼭ ������ ���� �˾Ƴ½��ϴ�. ó�� selected ���� �̸��� 
 * select�� �ߴµ� ������ ������ �����ϴ�. ������ �ý��� �� ��ɾ��� select�� �����ؼ�
 * �������� �̸����δ� ������� ���ϴ� �Ͱ����ϴ�. 
 * 
 * http://man7.org/linux/man-pages/man2/select.2.html �� �����ϼ���.
 *
 * ������ Ǯ�� ���� �����ϸ鼭 �����غ��� ��� map�� ������ �ʿ䰡 ���� ���մϴ�.
 * ���� 1�� �Է¹޴´ٸ� house�� push 2�� �Է¹޴´ٸ� chicken�� push���ָ� �� ����� �ڵ尡 �ɰͰ��׿�.
**/
void dfs(int cur) {
	if (selected.size() == m) {
		int sum = 0;
		for (int i = 0; i < house.size(); i++) {
			int tmp = INF;
			for (int j = 0; j < selected.size(); j++) {
				tmp = min(tmp, abs(house[i].first - selected[j].first) + abs(house[i].second - selected[j].second));
			}
			sum += tmp;
		}
		result = min(result, sum);
		return;
	}

	for (int i = cur; i < chicken.size(); i++) {
		selected.push_back(chicken[i]);
		dfs(i + 1);
		selected.pop_back();
	}
}

int main(void) {
	scanf("%d %d", &n, &m);
	for (int y = 0; y < n; y++) {
		for (int x = 0; x < n; x++) {
			scanf("%d", &map[y][x]);
			if (map[y][x] == 1)
				house.push_back(make_pair(y, x));
			else if (map[y][x] == 2)
				chicken.push_back(make_pair(y, x));
		}
	}
	result = INF;
	dfs(0);
	printf("%d\n", result);

	return 0;
}