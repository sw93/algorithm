import re

def solution(s):
    answer = [] # ����
    numberSet = s.split(',{') # ������ ����
    numberSet.sort(key = len) # ���� ũ�⸦ �������� ����

    for i in numberSet :
    	number = re.findall("\d+", i) # ���ڹ����� ����
    	for j in number :
    		if int(j) not in answer :
    			answer.append(int(j))
    return answer