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

ogprog = [int(x) for x in open('23.txt', 'r').read().split(',')]

def a():
    nics = [comp(ogprog, [i]) for i in range(50)]
    while True:
        for i in range(50):
            c = nics[i]
            if len(c.inpq) == 0:
                c.inpq.append(-1)
            c.run()
            while c.outq:
                d = c.outq.popleft()
                x = c.outq.popleft()
                y = c.outq.popleft()
                if d == 255:
                    return y
                nics[d].inpq.append(x)
                nics[d].inpq.append(y)

def b():
    nics = [comp(ogprog, [i]) for i in range(50)]
    NAT = (0, 0)
    py = None
    while True:
        idle = True
        for i in range(50):
            c = nics[i]
            if len(c.inpq) == 0:
                c.inpq.append(-1)
            c.run()
            while c.outq:
                idle = False
                d = c.outq.popleft()
                x = c.outq.popleft()
                y = c.outq.popleft()
                if d == 255:
                    NAT = (x, y)
                    continue
                nics[d].inpq.append(x)
                nics[d].inpq.append(y)
        if idle:
            x, y = NAT
            if y == py:
                return y
            py = y
            nics[0].inpq.append(x)
            nics[0].inpq.append(y)

print('Part 1', a())
print('Part 1', b())
