def solution(dartResult):
    answer = 0
    num_list = []
    i = 0
    dartResult = dartResult.replace('10','M')
    
    while(i < len(dartResult)): 
        if dartResult[i] == "M":
            num_list.append(10)   
        elif dartResult[i] == "D":
            num_list[-1] = num_list[-1] *num_list[-1] 
        elif dartResult[i] == "T":
            num_list[-1] = num_list[-1] *num_list[-1] * num_list[-1]
    
        elif dartResult[i] == "*":
            num_list[-1] = num_list[-1] * 2
            if len(num_list) > 1:
                num_list[len(num_list)-2] = num_list[len(num_list)-2] * 2
        elif dartResult[i]=="#":
            num_list[-1] = num_list[-1] * -1
        
        elif dartResult[i] != "S":
            num_list.append(ord(dartResult[i])-48)
            
        i = i + 1
            
    for i in num_list:
        answer += i
        
    return answer