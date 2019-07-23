#include <cstdio>
using namespace std;
int main(int argc, char** argv) {
	int t, a, b, c;
    scanf("%d", &t);
    for (int i=1; i<=t; i++) {
        scanf("%d %d %d", &a, &b, &c);
        printf("#%d %d\n", i, a>b?c/b:c/a);
    }
	return 0;
}
