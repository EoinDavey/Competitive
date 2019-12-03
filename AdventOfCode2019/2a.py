prog = [int(x) for x in input().split(',')]
prog[1] = 12
prog[2] = 2
ind = 0
while True:
    op = prog[ind]
    if op == 1:
        a, b, c = prog[ind+1:ind+4]
        prog[c] = prog[a] + prog[b]
        ind += 4
    elif op == 2:
        a, b, c = prog[ind+1:ind+4]
        prog[c] = prog[a] * prog[b]
        ind += 4
    elif op == 99:
        break
print(prog)
