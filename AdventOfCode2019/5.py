import sys
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


class comp:
    def __init__(self, prog, inp, out):
        self.prog = prog[:]
        self.ind = 0
        self.inp = inp
        self.out = out
        self.fns = {}
        self.args = {}

        self.regsimple(lambda a, b, c: c.set(a.get() + b.get()), 1, 3),
        self.regsimple(lambda a, b, c: c.set(a.get() * b.get()), 2, 3),
        self.regsimple(lambda a: a.set(self.inp()), 3, 1),
        self.regsimple(lambda a: self.out(a.get()), 4, 1),

        self.regsimple(lambda a, b, c: c.set(1 if a.get() < b.get() else 0), 7, 3)
        self.regsimple(lambda a, b, c: c.set(1 if a.get() == b.get() else 0), 8, 3)

        self.regjmp(lambda a, b: b.get() if a.get() != 0 else None, 5, 2)
        self.regjmp(lambda a, b: b.get() if a.get() == 0 else None, 6, 2)

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
            self.ind = [self.ind + nargs, jmp][jmp != None]

        self.reg(wrap, op, nargs)

    def run(self):
        self.ind = 0
        while True:
            opcode = self.prog[self.ind]
            op = opcode % 100
            pmode = opcode // 100
            if op == 99:
                break
            self.ind += 1
            nargs = self.args[op]
            if self.ind + nargs > len(self.prog):
                return None
            args = []
            for x in self.prog[self.ind : self.ind + nargs]:
                if pmode % 10 == 0:
                    args.append(aracc(x, self.prog))
                else:
                    args.append(vacc(x))
                pmode //= 10
            self.fns[op](*args)


ogprog = [int(x) for x in input().split(",")]

a = 0


def sta(x):
    global a
    a = x


b = 0


def stb(x):
    global b
    b = x


c = comp(ogprog, lambda: 1, sta)
c.run()
c = comp(ogprog, lambda: 5, stb)
c.run()
print("Part A", a)
print("Part B", b)
