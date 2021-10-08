from itertools import combinations

def solution(orders, course):
    
    # string -> set
    new_orders = []
    for i in orders:
        ex = set(i)
        new_orders.append(ex)
    
    answer = []
    
    for i in course:
        temp = []
        max_cnt = 0
        
        slice_words = []
        slice_words = set(slice_words)
        for order in orders:
            # 가능한 모든 조합의 합집합
            slice_words = slice_words.union(list(combinations(order, i)))

        for slice_word in slice_words:
            cnt = 0
            for k in new_orders:
                # 조합된 집합이 해당 단어의 부분집합인지 확인 
                if (set(slice_word) == set(slice_word).intersection(set(k))):
                    cnt = cnt +1
            if (cnt >= 2):
                if (max_cnt < cnt):
                    max_cnt = cnt
                    temp = []
                    temp.append(slice_word)
                elif (max_cnt == cnt):
                    temp.append(slice_word)
        
        if temp != []:
            for i in temp:
                temp_string = ''.join(sorted(i))
                answer.append(temp_string)
                
    answer = list(set(answer))
    answer.sort()
    return answer