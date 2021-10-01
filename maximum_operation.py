import copy

def calculate(expr,oper,a,b,c) :
    expression = copy.deepcopy(expr)
    oper_list = copy.deepcopy(oper)
    oper_list.append(-1)
    for j in [a,b,c]:
        i = 0
        while(oper_list[i] != -1): 
            if (oper_list[i] == j):
                if j == '+' : 
                    expression[i] = int(expression[i]) + int(expression[i+1])
                elif j == '-' :                                    
                    expression[i] = int(expression[i]) - int(expression[i+1])
                elif j == '*' : 
                    expression[i] = int(expression[i]) * int(expression[i+1])
                expression.pop(i+1)
                oper_list.remove(j)
            else : i = i+1
    return abs(expression[0])
           
            
def solution(expression):
    nums = expression.replace('-','+')
    nums = nums.replace('*','+')
    num_list = nums.split('+')
    oper_list = []
    for i in expression:
        if i == '+' or i == '-' or i == '*':
            oper_list.append(i)
    answer = 0
    answer = max(calculate(num_list,oper_list,'+','-','*'),
                  calculate(num_list,oper_list,'+','*','-'),
                  calculate(num_list,oper_list,'-','+','*'),
                  calculate(num_list,oper_list,'-','*','+'),
                  calculate(num_list,oper_list,'*','-','+'),
                  calculate(num_list,oper_list,'*','+','-'))
