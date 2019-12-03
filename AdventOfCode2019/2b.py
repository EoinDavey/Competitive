import sys

ogprog = [int(x) for x in input().split(',')]

def tst(noun, verb):
    prog = ogprog[:]
    prog[1] = noun
    prog[2] = verb
    ind = 0
    while True:
        op = prog[ind]
        if op == 1:
            if ind+3 >= len(prog):
                return None
            a, b, c = prog[ind+1:ind+4]
            prog[c] = prog[a] + prog[b]
            ind += 4
        elif op == 2:
            if ind+3 >= len(prog):
                return None
            a, b, c = prog[ind+1:ind+4]
            prog[c] = prog[a] * prog[b]
            ind += 4
        elif op == 99:
            break
    return prog[0]

for n in range(100):
    for v in range(100):
        ans = tst(n, v)
        if ans == None:
            continue
        if ans == 19690720:
            print(100*n+v)
            sys.exit(0)
