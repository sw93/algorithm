#include <iostream>
#include <cstring>
#include <algorithm>

using namespace std;

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	char ch[51];
	cin >> ch;
	int n = strlen(ch);
	int l = 0;
	int r = n - 1;
	int t;
	ch[r]++;

	while (l < r)
		if (ch[r--] > ch[l++])
			ch[r]++;

	t = l = (n - 1) / 2;
	while (ch[l] == '9' + 1){
		ch[l] = '0';
		ch[--l]++;
	}
	if (l < 0) {
		cout << 1;
		while (--n)
			cout << "0";
		return 0;
	}

	for (int i = 0; i <= t; i++)
		cout << ch[i];
	for (int i = t - n % 2; i >= 0; i--)
		cout << ch[i];
	return 0;
}