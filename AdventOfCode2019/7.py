import sys
from itertools import permutations
from functools import reduce

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

STOP = 10**100

class comp:
    def __init__(self, prog, inp, out):
        self.prog = prog[:]
        self.ind = 0
        self.inp = inp
        self.out = out
        self.fns = {}
        self.args = {}

        self.regsimple(lambda a,b,c: c.set(a.get()+b.get()), 1, 3),
        self.regsimple(lambda a,b,c: c.set(a.get()*b.get()), 2, 3),
        self.regsimple(lambda a: self.out(a.get()), 4, 1),

        self.regsimple(lambda a,b,c: c.set(1 if a.get() < b.get() else 0), 7, 3)
        self.regsimple(lambda a,b,c: c.set(1 if a.get() == b.get() else 0), 8, 3)

        self.regjmp(lambda a,b: b.get() if a.get() != 0 else None, 5, 2)
        self.regjmp(lambda a,b: b.get() if a.get() == 0 else None, 6, 2)

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

            if op == 3: # input, None means halt
                val = self.inp()
                if val == None:
                    return STOP
                self.prog[self.prog[self.ind+1]] = val
                self.ind += 2
                continue

            self.ind += 1
            nargs = self.args[op]
            if self.ind + nargs > len(self.prog):
                return None
            args = []
            for x in self.prog[self.ind:self.ind+nargs]:
                if pmode%10 == 0:
                    args.append(aracc(x, self.prog))
                else:
                    args.append(vacc(x))
                pmode //= 10
            self.fns[op](*args)

def a(prog):
    outs = []
    for perm in permutations([0,1,2,3,4]):
        inp = 0
        for i in range(5):
            igen = (x for x in [perm[i], inp])
            def outf(x):
                nonlocal inp
                inp = x
            c = comp(prog, igen.__next__, outf)
            c.run()
        outs.append(inp)
    return max(outs)

def b(prog):
    mx = 0
    for perm in permutations([9,8,7,6,5]):
        v = 0

        def ign(y):
            yield perm[y]
            while True:
                yield v
                yield None

        ifns = [ign(x) for x in range(5)]

        def ofn(x):
            nonlocal v
            v = x

        amps = [comp(prog, ifns[x].__next__, ofn) for x in range(5)]

        stopped = False
        while not stopped:
            for i in range(5):
                stopval = amps[i].run()
                if stopval == None:
                    stopped = True
        mx = max(mx, v)
    return mx

ogprog = [int(x) for x in input().split(',')]
print('Part A', a(ogprog))
print('Part B', b(ogprog))
