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
	while (tmp != string::npos) {	// 찾는 문자열이 없을때까지 반복
		cnt++;
		// 해당 글자를 찾은 위치부터 다시 찾는다.
		tmp = doc.find(word, tmp + word.size());
	}
	cout << cnt;
}