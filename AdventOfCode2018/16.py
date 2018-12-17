import sys
from collections import Counter, deque, defaultdict
from heapq import heappush, heappop

ls = [line.strip() for line in sys.stdin]

def addr(reg, op):
    o = reg[:]
    A, B, C = op[1:]
    o[C] = o[A] + o[B]
    return o

def addi(reg, op):
    o = reg[:]
    A, B, C = op[1:]
    o[C] = o[A] + B
    return o

def mulr(reg, op):
    o = reg[:]
    A, B, C = op[1:]
    o[C] = o[A] * o[B]
    return o

def muli(reg, op):
    o = reg[:]
    A, B, C = op[1:]
    o[C] = o[A] * B
    return o

def banr(reg, op):
    o = reg[:]
    A, B, C = op[1:]
    o[C] = o[A] & o[B]
    return o

def bani(reg, op):
    o = reg[:]
    A, B, C = op[1:]
    o[C] = o[A] & B
    return o

def borr(reg, op):
    o = reg[:]
    A, B, C = op[1:]
    o[C] = o[A] | o[B]
    return o

def bori(reg, op):
    o = reg[:]
    A, B, C = op[1:]
    o[C] = o[A] | B
    return o

def setr(reg, op):
    o = reg[:]
    A, B, C = op[1:]
    o[C] = o[A]
    return o

def seti(reg, op):
    o = reg[:]
    A, B, C = op[1:]
    o[C] = A
    return o

def gtir(reg, op):
    o = reg[:]
    A, B, C = op[1:]
    o[C] = 1 if  A > o[B] else 0
    return o

def gtri(reg, op):
    o = reg[:]
    A, B, C = op[1:]
    o[C] = 1 if o[A] > B else 0
    return o

def gtrr(reg, op):
    o = reg[:]
    A, B, C = op[1:]
    o[C] = 1 if o[A] > o[B] else 0
    return o

def eqir(reg, op):
    o = reg[:]
    A, B, C = op[1:]
    o[C] = 1 if A == o[B] else 0
    return o

def eqri(reg, op):
    o = reg[:]
    A, B, C = op[1:]
    o[C] = 1 if o[A] == B else 0
    return o

def eqrr(reg, op):
    o = reg[:]
    A, B, C = op[1:]
    o[C] = 1 if o[A] == o[B] else 0
    return o

ops = [addr,addi,mulr,muli, banr,bani,borr,bori, setr, seti, gtir, gtri, gtrr, eqir, eqri, eqrr]

tot = 0
i = 0
samps = defaultdict(list)
while True:
    if not ls[i] or ls[i][0] != 'B':
        break
    regb = eval(' '.join(ls[i].split()[1:]))
    op = map(int, ls[i+1].split())
    rega = eval(' '.join(ls[i+2].split()[1:]))

    samps[op[0]].append((regb, rega, op))

    cnt = 0
    for f in ops:
        if f(regb, op) == rega:
            cnt+=1

    if cnt >= 3:
        tot+=1
    i += 4

prog = []
while i < len(ls):
    if ls[i]:
        prog.append(map(int, ls[i].split()))
    i+=1

print "part 1:", tot

usd = [False]*len(ops)

fls = defaultdict(set)

for code in xrange(16):
    for k in xrange(len(ops)):
        f = ops[k]

        pas = True
        for (regb, rega, op) in samps[code]:
            if f(regb, op) != rega:
                pas=False
                break
        if pas:
            fls[code].add(k)
print fls

fmap = {}

while not all(usd):
    order = filter(lambda x: not usd[x], xrange(16))
    code = min(order, key=lambda x: len(fls[x]))
    if len(fls[code]) == 0:
        print 'fukd'
        break

    k = fls[code].pop()
    fmap[code] = k
    usd[code] = True

    for c in xrange(16):
        if usd[c]:
            continue
        if k in fls[c]:
            fls[c].remove(k)

reg = [0]*4
for com in prog:
    reg = ops[fmap[com[0]]](reg, com)
print reg
