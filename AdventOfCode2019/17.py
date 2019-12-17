import sys
import re
from itertools import permutations
from functools import reduce
from collections import defaultdict, deque

class aracc:
    def __init__(self, pos, ls):
        self.pos = pos
        self.ls = ls

    def get(self):
        return self.ls[self.pos]

    def set(self, v):
        self.ls[self.pos] = v

class vacc:
    def __init__(self, val):
        self.val = val
    def get(self):
        return self.val

class relacc:
    def __init__(self, val, comp):
        self.val = val
        self.comp = comp

    def get(self):
        return self.comp.prog[self.val + self.comp.rel]

    def set(self, v):
        self.comp.prog[self.val + self.comp.rel] = v

class comp:
    def __init__(self, prog, inpq):
        self.prog = defaultdict(int)
        self.prog.update(zip(range(len(prog)),prog))
        self.ind = 0
        self.rel = 0
        self.fns = {}
        self.args = {}
        self.inpq = deque(inpq)
        self.outq = deque()

        self.regsimple(lambda a,b,c: c.set(a.get()+b.get()), 1, 3),
        self.regsimple(lambda a,b,c: c.set(a.get()*b.get()), 2, 3),

        self.regsimple(lambda a: a.set(self.inpq.popleft()), 3, 1),
        self.regsimple(lambda a: self.outq.append(a.get()), 4, 1),

        self.regjmp(lambda a,b: b.get() if a.get() != 0 else None, 5, 2)
        self.regjmp(lambda a,b: b.get() if a.get() == 0 else None, 6, 2)

        self.regsimple(lambda a,b,c: c.set(1 if a.get() < b.get() else 0), 7, 3)
        self.regsimple(lambda a,b,c: c.set(1 if a.get() == b.get() else 0), 8, 3)
        self.regsimple(lambda a: self.adjustRel(a.get()), 9, 1)

    def adjustRel(self, v):
        self.rel += v

    def reg(self, fn, op, nargs):
        self.fns[op] = fn
        self.args[op] = nargs

    def regsimple(self, fn, op, nargs):
        def wrap(*argv):
            fn(*argv)
            self.ind += nargs
        self.reg(wrap, op, nargs)

    def regjmp(self, fn, op, nargs):
        def wrap(*argv):
            jmp = fn(*argv)
            self.ind = [self.ind+nargs, jmp][jmp != None]
        self.reg(wrap, op, nargs)

    def run(self):
        while True:
            opcode = self.prog[self.ind]
            op = opcode%100
            pmode = opcode//100
            if op == 99:
                break

            if op == 3 and len(self.inpq) == 0:
                return True

            self.ind += 1
            nargs = self.args[op]
            if self.ind + nargs > len(self.prog):
                return False
            args = []
            for ix in range(self.ind, self.ind+nargs):
                x = self.prog[ix]
                if pmode%10 == 0:
                    args.append(aracc(x, self.prog))
                elif pmode%10 == 2:
                    args.append(relacc(x, self))
                else:
                    args.append(vacc(x))
                pmode //= 10
            self.fns[op](*args)
        return False

ogprog = [int(x) for x in input().split(',')]
mvs = [(-1, 0), (0, 1), (1, 0), (0, -1)]
c = comp(ogprog, [])
c.run()
board = []
rw = []
for x in c.outq:
    if x == 10:
        if rw:
            board.append(rw)
        rw = []
    else:
        rw.append(chr(x))
H = len(board)
W = len(board[0])

def a(prog):
    sm = 0
    for x in range(H):
        for y in range(W):
            if not board[x][y] == '#':
                continue
            cnt = 0
            for mv in mvs:
                nx, ny = x + mv[0], y + mv[1]
                if not (0 <= nx < H and 0 <= ny < W):
                    continue
                cnt += board[nx][ny] == '#'
            if cnt == 4:
                sm += x*y
    return sm

def pb():
    for rw in board:
        print(''.join(rw))
def b():
    x, y = [(x,y) for x in range(H) for y in range(W) if board[x][y]=='^'][0]
    tgts = set((x,y) for x in range(H) for y in range(W) if board[x][y]=='#')
    dr=0
    pth = []
    while tgts:
        l = [3,0,1,2][dr]
        r = [1,2,3,0][dr]
        for idx in [dr, l, r]:
            nx, ny = x + mvs[idx][0], y + mvs[idx][1]
            if not (0 <= nx < H and 0 <= ny < W and board[nx][ny] == '#'):
                continue
            x, y = nx, ny
            if idx == l:
                pth.append('L')
            if idx == r:
                pth.append('R')
            pth.append('f')
            dr = idx
            if (x,y) in tgts:
                tgts.remove((x,y))
            break
    return pth

def compr(pth):
    npth = []
    rn = 0
    for x in pth:
        if x == 'R' or x == 'L':
            if rn:
                npth.append(rn)
            rn = 0
            npth.append(x)
            continue
        rn += 1
    if rn:
        npth.append(rn)
    return npth

print(a(ogprog))

pth = compr(b())
tst(pth)
P = len(pth)
S = ','.join(map(str, pth))+','

def findMatch(S):
    qs = set()
    seq = {}
    for ln in range(1, 11):
        for x in range(3**ln):
            ls = []
            for i in range(ln):
                ls.append(chr((x//(3**i))%3 + ord('A')))
            q = "^"
            s = {}
            for x in ls:
                if x in s:
                    q += f'\\{s[x]}'
                else:
                    q += '(.+)'
                    s[x] = len(s)+1
            q += "$"
            qs.add(q)
            seq[q] = ls

    for q in qs:
        x = re.search(q, S)
        if x:
            ls = x.groups()
            if not all(map(lambda x: len(x) <= 21, ls)):
                continue
            return [x.split(',')[:-1] for x in ls], seq[q]

def b(prog, S):
    gps, seq = findMatch(S)
    for x in permutations([0,1,2]):
        inps = []
        inps += [ord(x) for x in ','.join(seq)+'\n']
        for i in x:
            inps += [ord(x) for x in ','.join(gps[i])+'\n']
        inps += [ord(x) for x in 'n\n']
        c = comp(prog, inps)
        c.prog[0] = 2
        c.run()
        for x in c.outq:
            if x > 128:
                return(x)

print(b(ogprog, S))
