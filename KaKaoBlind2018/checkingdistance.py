def dfsr(places,x,y,answer):
    if (x>=5): return False
    if (y>=5): return False
    if places[x][y] == 'X':
        return False
    if places[x][y] == 'P':
        if answer >2 : 
            return False
        else :
            return True
    if places[x][y] == 'O':
        return (dfsr(places,x+1,y,answer +1) or dfsr(places,x,y+1,answer +1))

def dfsl(places,x,y,answer):
    if (x<0): return False
    if (y>=5): return False
    if places[x][y] == 'X':
        return False
    if places[x][y] == 'P':
        if answer >2 : 
            return False
        else :
            return True
    if places[x][y] == 'O':
        return (dfsl(places,x-1,y,answer +1) or dfsl(places,x,y+1,answer +1))
    
    
def solution(places):
    answer = []
    for i in places:
        flag = True
        for x in range(5) :
            for y in range(5):
                if i[x][y] == 'P':
                    if(dfsr(i,x+1,y,1) or dfsr(i,x,y+1,1) or dfsl(i,x-1,y,1)or dfsl(i,x,y+1,1)):
                        flag = False
        if(flag):
            answer.append(1)
        else:
            answer.append(0)

    return answer