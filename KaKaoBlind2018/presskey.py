def solution(numbers, hand):
    answer = ''
    l = 10
    r = 12
    for i in numbers:
        if i == 0 : 
            i = 11
        if (i == 1 or i == 4 or i == 7): 
            answer = answer +'L'
            l = i
        elif (i == 3 or i == 6 or i == 9 ): 
            answer = answer+'R'
            r = i
        else :
            l_state = abs(((l-1 )// 3) - ((i-1 )// 3)) + abs(((l-1 )% 3) - ((i-1 )% 3))
            r_state = abs(((r-1 )// 3) - ((i-1 )// 3)) + abs(((r-1 )% 3) - ((i-1 )% 3))
            if l_state == r_state :
                if hand == "right":
                    answer = answer+ 'R'
                    r = i
                else:
                    answer = answer +'L'
                    l = i
            elif l_state > r_state:
                answer =answer + 'R'
                r = i
            else:
                answer =answer + 'L'
                l = i
            
    return answer