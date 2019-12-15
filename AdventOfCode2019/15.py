import sys
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

def mv(pos, dr):
    dx = {1:-1, 2:1, 3:0, 4:0}[dr]
    dy = {1:0, 2:0, 3:-1, 4:1}[dr]
    return (pos[0]+dx, pos[1]+dy)

TGT = (0,0)
def buildGraph(prog):
    c = comp(prog, [])
    back = {1:2, 2:1, 3:4, 4:3}

    vis = set()
    adjList = defaultdict(list)
    def srch(pos):
        global TGT
        vis.add(pos)
        for dr in range(1,5):
            np = mv(pos,dr)
            c.inpq.append(dr)
            c.run()
            x = c.outq.popleft()
            if not x:
                continue
            adjList[pos].append(np)
            if x == 2:
                TGT = np
            if np not in vis:
                srch(np)
            c.inpq.append(back[dr])
            c.run()
            c.outq.popleft()

    srch((0,0))
    return adjList

adjList = buildGraph(ogprog)

def dist(s):
    q = deque([s])
    d = defaultdict(lambda: 10**100)
    d[s] = 0
    while q:
        u = q.popleft()
        for v in adjList[u]:
            if v in d:
                continue
            d[v] = d[u] + 1
            q.append(v)
    return d

print(dist((0,0))[TGT])
print(max(dist(TGT).values()))
