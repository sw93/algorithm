#include <stdio.h>
#include <string.h>
int main()
{
    int n;
    scanf("%d", &n);
    int cnt=0;
    while(n--) {
        char s[101];
        bool chk[26]={0,};
        scanf("%s", &s);
        chk[s[0]-'a']=1;
        int prev, cur;
        bool duplicateFlag=0;
        for(int i=1; i<strlen(s); i++) {
            cur=s[i]-'a';
            prev=s[i-1]-'a';
            if(chk[cur] && cur != prev) duplicateFlag=1;
            chk[cur]=1;
        }
        if(!duplicateFlag) cnt++;
    }
    printf("%d\n", cnt);
    return 0;
}