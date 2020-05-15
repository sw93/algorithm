import re

def solution(s):
    answer = [] # 정답
    numberSet = s.split(',{') # 집합을 구함
    numberSet.sort(key = len) # 집합 크기를 기준으로 정렬

    for i in numberSet :
    	number = re.findall("\d+", i) # 숫자묶음을 추출
    	for j in number :
    		if int(j) not in answer :
    			answer.append(int(j))
    return answer