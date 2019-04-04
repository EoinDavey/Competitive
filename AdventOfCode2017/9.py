s = raw_input()

stk = [('{',0)]

i = 0
sm = 0
canc = 0
while i < len(s):
    v = s[i]
    if v=='!':
        i+=2
        continue
    if v=='}':
        if stk[-1][0] == '{':
            sm += stk[-1][1]
            stk.pop()
        if stk[-1][0] == '<':
            canc+=1
    elif v=='>':
        if stk[-1][0] == '<':
            stk.pop()
    elif v=='<':
        if stk[-1][0] != '<':
            stk.append(('<',0))
        elif stk[-1][0] == '<':
            canc+=1
    elif v=='{':
        if stk[-1][0] == '{':
            stk.append(('{', stk[-1][1]+1))
        elif stk[-1][0] == '<':
            canc+=1
    else:
        if stk[-1][0] == '<':
            canc+=1
    i+=1
print canc
