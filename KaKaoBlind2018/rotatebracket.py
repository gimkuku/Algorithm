def checkpair(a,b):
    if a == '(':
        if b == ')': return True
    elif a ==  '{':
        if b == '}': return True
    elif a ==  '[':
        if b == ']': return True
    return False

def checkstack(origins):
    s = origins[:]
    stack = []
    top = -1
    answer = 0
    for i in s:
        new = i
        if top != -1:
            if (checkpair(stack[top],new)):
                stack.pop()
                if top == 0:
                    answer = answer +1 
                top = top -1
            else:
                stack.append(new)
                top = top +1
        else : 
            stack.append(new)
            top = top +1
    if top == -1 :
        return answer
    else:
        return 0


def solution(s):
    doubles = s + s
    answer = 0
    for i in range(len(doubles)):
        if ((doubles[i] == '(') or (doubles[i] == '{') or (doubles[i] =='[')):
            tests = doubles[i:i+len(s)] 
            answer = checkstack(tests)
            if (answer == 0):
                continue
            else:
                break
    return answer