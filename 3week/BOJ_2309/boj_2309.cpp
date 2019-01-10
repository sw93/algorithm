#include <iostream>
#include <algorithm>
#include <stdlib.h>

using namespace std;

#define N 9
#define MAX 100
int arr[N];
bool breakFlag = false;
void sol()
{
	int tmp = 0;
	for (int i = 0; i < N; i++) {
		cin >> arr[i];
		tmp += arr[i];
	}

	for (int i = 0; i < N - 1; i++) {
		for (int j = i + 1; j < N; j++) {
			if (tmp - arr[i] - arr[j] == MAX)
			{
				arr[i] = -1;
				arr[j] = -1;
				breakFlag = true;
			}
		}
		if (breakFlag)
			break;
	}
	sort(arr, arr + N);
	for (int i = 2; i < N; i++)
		cout << arr[i] << endl;
}

int main()
{
	sol();
	return 0;
}
