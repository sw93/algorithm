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
 * 시간복잡도는 계산하지 못하겠다. 최대 13개의 치킨집에서 최대 13개를 고르는 것인데 
 * 순서는 상관이 없으므로 최악의 경우 13C6 일거라 생각된다. 때문에 1초라는 제한시간 내에 전체탐색으로
 * 풀이할 수 있다고 생각되어 dfs로 풀이하였습니다. (혹시 시간복잡도 아시는 분은 댓글 부탁드립니다 ㅜㅜ)
 * 
 * 연구소 문제와 같이 map을 입력받을 때 집과 치킨집의 좌표를 따로 저장했습니다.
 * 이후 dfs를 통해 치킨집을 순서에 관계없이 선택하고 selected 벡터에 저장합니다. 
 * 이 selected벡터의 사이즈가 m인경우 문제에서 주어진 최대 치킨집의 갯수이므로
 * 집과 치킨집의 거리를 계산해서 최소값을 저장해주는 문제입니다.
 * 
 * 여기서 주의할 점을 알아냈습니다. 처음 selected 벡터 이름을 
 * select로 했는데 컴파일 에러가 났습니다. 리눅스 시스템 콜 명령어중 select가 존재해서
 * 전역변수 이름으로는 사용하지 못하는 것같습니다. 
 * 
 * http://man7.org/linux/man-pages/man2/select.2.html 를 참조하세요.
 *
 * 문제를 풀고 지금 리뷰하면서 생각해보니 사실 map을 선언할 필요가 없을 듯합니다.
 * 만약 1을 입력받는다면 house에 push 2를 입력받는다면 chicken에 push해주면 더 깔끔한 코드가 될것같네요.
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