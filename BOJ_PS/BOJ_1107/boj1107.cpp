#include <iostream>
#include <algorithm>
using namespace std;
int n, m;
bool brokenButton[10];

// 숫자버튼을 누른 채널으로 이동 가능한지 확인하는 함수
bool checkButton(int channel) {
	if (channel == 0) {
		if (brokenButton[0]) return false;
		else return true;
	}
	while (channel) {
		if (brokenButton[channel % 10]) return false;
		else channel /= 10;
	}
	return true;
}

// checkButton을 통과한 채널의 자릿수를 구하는 함수
int getChannelDigit(int channel) {
	int ret = 0;
	if (channel == 0) return 1;
	while (channel) {
		channel /= 10;
		ret++;
	}
	return ret;
}

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0);
	cin >> n >> m;
	int buttonNumber;
	for (int i = 0; i < m; i++) {
		cin >> buttonNumber;
		brokenButton[buttonNumber] = 1;
	}

	int ans = 987654321;

	// 뒤에서 탐색하는게 더 효과적인 경우도 있으므로 n의 범위를 2배 늘림
	// 예를 들어 6버튼만 안고장나고 60만번 채널로 이동하고 싶은 경우
	// 초기 100번 채널에서 +버튼만 누르는 것 보다 666,666채널에서 -버튼을 누르는 횟수가 더 적음
	for (int i = 0; i <= 1000000; i++) {
		int channel = i;
		if (checkButton(channel)) {

			// 숫자버튼을 눌러 이동할때 필요한 자릿수
			int digit = getChannelDigit(channel);

			// 숫자버튼 이동과 +버튼 또는 -버튼 클릭의 합을 비교
			ans = min(ans, digit + abs(n - channel));
		}
	}

	cout << min(ans, abs(n - 100));
	return 0;
}