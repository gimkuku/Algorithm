def solution(numbers):
    answer = []
    bin_numbers = []
    for i in numbers:
        element= bin(i)
        list_e = list(element)
        list_e.insert(2,'0')
        element = ''.join(list_e)
        bin_numbers.append(element)
    
    for i in bin_numbers:
        for j in range(len(i)-2):
            if ((i[len(i)-1-j] == '0') and (j == 0)):
                list_i = list(i)
                list_i[len(i)-1-j] = '1'
                i = ''.join(list_i)
                break
            elif ((i[len(i)-1-j] == '0') and (i[len(i)-j-2] != 'b')):
                list_i = list(i)
                list_i[len(i)-1-j] = '1'
                list_i[len(i)-j] = '0'
                i = ''.join(list_i)
                break
            elif ((i[len(i)-1-j] == '0') and (i[len(i)-j-2] == 'b')):
                list_i = list(i)
                list_i[len(i)-1-j] = '1'
                list_i[len(i)-j] = '0'
                i = ''.join(list_i)
                break
                
        answer.append(int(i,2))
                
    return answer