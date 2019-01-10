#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	string doc, word;
	int cnt = 0;
	getline(cin, doc);
	getline(cin, word);

	auto tmp = doc.find(word);
	while (tmp != string::npos) {	// ã�� ���ڿ��� ���������� �ݺ�
		cnt++;
		// �ش� ���ڸ� ã�� ��ġ���� �ٽ� ã�´�.
		tmp = doc.find(word, tmp + word.size());
	}
	cout << cnt;
}