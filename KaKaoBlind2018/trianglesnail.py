def solution(n):
    answer = []
    answer_list = []
    
    for i in range(n):
        element = []
        answer_list.append(element)
    
    size = n-1
    index = 1
    start = 0
    end = 0
    while (size > 0):
        if index < int(((n + 1) * n)/2): 
            for i in range(size):
                answer_list[start + i].insert(int(start/2),index)
                index = index +1
            for i in range(size):
                answer_list[n-end-1].insert(int(start/2)+i,index)
                index = index +1
            for i in range(size):
                answer_list[n-1 - i -end].insert(int(len(answer_list[n -1- i -end])-(end)),index)
                index = index + 1
        size = size -3
        start = start +2
        end= end +1
        
    if index == int(((n + 1) * n)/2): 
        answer_list[start].insert(int(start/2),index)
        
    for i in answer_list:
        for j in i:
            answer.append(j)
            
            
    return answer