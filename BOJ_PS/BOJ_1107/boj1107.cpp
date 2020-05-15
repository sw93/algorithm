#include <iostream>
#include <algorithm>
using namespace std;
int n, m;
bool brokenButton[10];

// ���ڹ�ư�� ���� ä������ �̵� �������� Ȯ���ϴ� �Լ�
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

// checkButton�� ����� ä���� �ڸ����� ���ϴ� �Լ�
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

	// �ڿ��� Ž���ϴ°� �� ȿ������ ��쵵 �����Ƿ� n�� ������ 2�� �ø�
	// ���� ��� 6��ư�� �Ȱ��峪�� 60���� ä�η� �̵��ϰ� ���� ���
	// �ʱ� 100�� ä�ο��� +��ư�� ������ �� ���� 666,666ä�ο��� -��ư�� ������ Ƚ���� �� ����
	for (int i = 0; i <= 1000000; i++) {
		int channel = i;
		if (checkButton(channel)) {

			// ���ڹ�ư�� ���� �̵��Ҷ� �ʿ��� �ڸ���
			int digit = getChannelDigit(channel);

			// ���ڹ�ư �̵��� +��ư �Ǵ� -��ư Ŭ���� ���� ��
			ans = min(ans, digit + abs(n - channel));
		}
	}

	cout << min(ans, abs(n - 100));
	return 0;
}