#include <stdlib.h>
#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	string str;
	cin >> str;
	int size = str.size();
	char *result = (char *)malloc(size);

	sort(str.begin(), str.end());

	for (int i = 0; i < size/2; i++) {
		if (str[i] != str[size - i - 1])
			result[i] = str[i], result[size - i - 1] = str[i];
	}

	cout << str;
	return 0;
}