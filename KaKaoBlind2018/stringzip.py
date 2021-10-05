def solution(s):
    answer = 0
    minans = len(s)
    
    for i in range(1,len(s) // 2+1):
        cut = s[0:i]
        cnt = 1
        answer = len(cut)
        
        for j in range(1,len(s)//i+1):
            new = s[i*j:i*(j+1)]
            if (cut == new):
                cnt = cnt +1
            else:
                if(cnt != 1 and cnt < 10):
                    answer = answer + 1
                elif(cnt > 9 and cnt < 100):
                    answer = answer + 2
                elif(cnt > 99 and cnt < 1000):
                    answer = answer + 3
                elif(cnt > 999):
                    answer = answer + 4
                cnt = 1
                cut = new
                answer = answer + len(new)
        answer = answer + len(s[i*(len(s)//i+1):])        
        if minans > answer:
            minans = answer
        answer = 0
                    
    return minans