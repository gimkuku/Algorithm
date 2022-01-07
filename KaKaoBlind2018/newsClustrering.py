def solution(str1, str2):
    answer = 0
    str1 = str1.lower()
    str2 = str2.lower()
    str_list1 = []
    cnt_inter = 0
    cnt_union = 0
    
    for index in range(len(str1)):
        if index != len(str1) -1:
            if ('a'<=str1[index] and str1[index]<='z') and ('a'<=str1[index+1] and str1[index+1]<='z'):
                str_list1.append(ord(str1[index])*128 + ord(str1[index+1]))
                cnt_union = cnt_union + 1
        
    for index in range(len(str2)):
        if index != len(str2)-1:
            if ('a'<=str2[index] and str2[index]<='z') and ('a'<=str2[index+1] and str2[index+1]<='z'):
                target = ord(str2[index])*128 + ord(str2[index+1])
                if target in str_list1:
                    cnt_inter = cnt_inter +1
                    str_list1.remove(target)
                else:
                    cnt_union = cnt_union +1
                    
    answer = 65536
    if cnt_union != 0:
        answer = (cnt_inter / cnt_union ) *65536
    answer = int(answer)
    return answer