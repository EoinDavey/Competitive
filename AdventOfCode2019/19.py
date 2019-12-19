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

cache = {}
def check(x, y):
    if (x, y) in cache:
        return cache[x, y]
    c = comp(ogprog, [x,y])
    c.run()
    ans = c.outq.popleft()
    cache[x,y] = ans
    return ans

def a():
    cnt = 0
    for i in range(50):
        for j in range(50):
            cnt += check(j, i)
    return cnt

def findStrt(rw):
    i = 0
    while not check(i, rw):
        i += 1
    assert(check(i, rw) and not check(i - 1, rw))
    return i

def findEnd(st, rw):
    i = st
    while check(i, rw):
        i += 1
    assert(check(i - 1, rw) and not check(i, rw))
    return i - 1

def testrw(rw):
    return findEnd(findStrt(rw), rw) - findStrt(rw+99) + 1 >= 100

def checkSq(x, y):
    for i in range(100):
        for j in range(100):
            if not check(x + i, y + j):
                return False
    return True

def b():
    L, R = 10, 2000
    while L < R:
        md = (L + R)//2
        if testrw(md):
            R = md
        else:
            L = md + 1
    fst = findStrt(L + 99)
    Y = L; X = fst
    mn = 10**100
    for dx in range(10):
        for dy in range(10):
            if checkSq(X - dx, Y - dy):
                mn = min(mn, (X-dx)*10000+(Y-dy))
    return mn

print(a())
print(b())
