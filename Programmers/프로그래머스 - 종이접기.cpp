#include <string>
#include <vector>

using namespace std;
/*
* ��Ģ 
* n = 1 -> 0
* n = 2 -> 0 0 1
* n = 3 -> 0 0 1 0 0 1 1
* n = 4 -> 0 0 1 0 0 1 1 0 0 0 1 1 0 1 1
* n = 2 -> 3�� �ɶ� 0 0 1�� 0 1 1 �� ���� ���� 0�� 1�� 1�� 0���� �ٲ�� ��� 0�� ���� ���� �� �� ����
* n = 3 -> 4�� �ɶ��� ���� 3�� ���� 0�� �߰� �ǰ� �������� 0�� 1�� 1�� 0���� �ٲ�
*/
vector<int> solution(int n) {
    vector<int> answer;
    answer.push_back(0);
    if (n == 1) return answer;
    for (int i=2; i<=n; i++) {
        vector<int> temp = answer;
        answer.push_back(0);
        for (int j=temp.size()-1; j>=0; j--) {
            if (temp[j] == 0) answer.push_back(1);
            else if (temp[j] == 1) answer.push_back(0);
        }
    }
    
    return answer;
}