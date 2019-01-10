#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	vector<int> alpha(26, 0);
	string str;
	cin >> str;

	for (int i = 0; i < str.size(); i++) {
		if (str[i] >= 'a')
			str[i] -= ('a' - 'A');
		alpha[str[i] - 'A']++;
	}
	int check = 0;
	int idx = 0;
	int max = *max_element(alpha.begin(), alpha.end());
	for (int i = 0; i < alpha.size(); i++)
		if (max == alpha[i])
			check++, idx = i;

	if (check > 1)
		cout << "?";
	else
		cout << static_cast<char>(idx + 'A');
	return 0;
}