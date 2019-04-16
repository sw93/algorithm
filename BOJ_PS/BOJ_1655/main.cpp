#include <iostream>
#include <queue>
#include <algorithm>
using namespace std;
/**
 * priority_queue<자료형, 구현체(container), 비교 연산자(compare 함수)>로 정의
 * priority_queue<int, vector<int>, greater<int> > pq;
 * 자료형은 int형이고 값의 저장방식은 vector<int>이며 최소값을 먼저 내놓는다.
 * greater가 최소값을 내뱉고 less가 최대값을 내뱉음
 *
 * 중간값 구하기 알고리즘
 * 최대 힙의 크기 = 최소힙의 크기  or  최소힙의 크기 + 1
 * 최대 힙의 root(최대값) <= 최소힙의 root(최소값)
 * 위 2가지 규칙이 맞지 않는다면 최대힙, 최소힙의 top을 swap한다.
 */
int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    priority_queue<int, vector<int>, less<int> > max_heap;
    priority_queue<int, vector<int>, greater<int> > min_heap;

    int n, num;
    cin>>n;
    while(n--) {
        cin>>num;
        if(max_heap.empty() && min_heap.empty()) max_heap.push(num);
        else if(max_heap.size() == min_heap.size()) max_heap.push(num);
        else min_heap.push(num);

        if(!max_heap.empty() && !min_heap.empty() && max_heap.top() > min_heap.top()) {
            int tmp=max_heap.top();
            max_heap.pop();
            max_heap.push(min_heap.top());
            min_heap.pop();
            min_heap.push(tmp);
        }
        cout<<max_heap.top()<<"\n";
    }
    return 0;
}