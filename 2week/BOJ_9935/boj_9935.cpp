#include <iostream>
#include <string>

using namespace std;

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	string str, result, bomb;
	int idx=0;
	bool flag;

	cin >> str >> bomb;
	int slen = str.size();
	int blen = bomb.size();

	for (int i = 0; i < slen; i++) {
		result += str[i];
		idx++;

		if (result[idx - 1] == bomb[blen - 1] && result.size() >= blen) {
			flag = true;
			for (int j = 0; j < blen; j++) {
				if (result[idx - blen + j] != bomb[j]) {
					flag = false;
					break;
				}
			}
			if (flag) {
				idx -= blen;
				result.erase(idx, blen);
			}
		}
	}

	if (result.size() == 0)
		cout << "FRULA";
	else
		cout << result;
	return 0;
}