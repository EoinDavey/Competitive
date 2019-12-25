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

ogprog = [int(x) for x in open('25.txt', 'r').read().split(',')]
c = comp(ogprog, [])
back = {
        'north':'south',
        'south':'north',
        'west':'east',
        'east':'west',
        'start':'none'
}

def say(x):
    for ch in x:
        c.inpq.append(ord(ch))
    c.inpq.append(ord('\n'))

def drain():
    c.run()
    s = ""
    while c.outq:
        s += chr(c.outq.popleft())
    return s
items = [
        'wreath',
        'weather machine',
        'candy cane',
        'prime number',
        'food ration',
        'astrolabe',
        'hypercube',
        'space law space brochure',
]
def exp(p):
    global c
    s = drain()
    if 'Alert' in s:
        return []
    for it in items:
        if it in s:
            say('take '+ it)
            drain()
    ans = None
    for x in ['north', 'south', 'east', 'west']:
        if not x in s or x == back[p]:
            continue
        say(x)
        e = exp(x)
        if e != None:
            ans = [x] + e
        say(back[x])
        drain()
    return ans

dirs = exp('start')
for d in dirs:
    say(d)
drain()

for i in range(2 ** len(items)):
    ls = []
    for j in range(len(items)):
        if (i & (1 << j))!= 0:
            ls.append(items[j])
    for l in ls:
        say('drop ' + l)
    drain()
    say(dirs[-1])
    s = drain()
    if 'Alert' not in s:
        print(s)
        break
    for l in ls:
        say('take ' + l)
