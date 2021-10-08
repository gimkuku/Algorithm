def solution(s):
    cnt_0 = 0
    cnt_2 = 0
    
    while (len(s) > 1):
        cnt_2 = cnt_2 +1
        cnt = 0
        # 0 지우고 글자수 세기
        for i in s:
            if (i == '1'):
                cnt = cnt + 1
        # 0 제거된 횟수
        cnt_0 = cnt_0 + len(s) - cnt
        
        # cnt 를 2진수로
        s = bin(cnt)
        s = s[2:]
        
    answer = []
    answer.append(cnt_2)
    answer.append(cnt_0)
    return answer