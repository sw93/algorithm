#include <iostream>
using namespace std;
int main() {
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    int num, sum=0;
    for(int i=1; i<=5; i++) {
        cin>>num;
        if(num<40)  sum+=40;
        else sum+=num;
    }
    cout<<sum/5;
    return 0;
}