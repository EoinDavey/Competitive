import sys
from itertools import permutations
from functools import reduce
from collections import defaultdict

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
    def __init__(self, prog, inp, out):
        self.prog = defaultdict(int)
        self.prog.update(zip(range(len(prog)),prog))
        self.ind = 0
        self.rel = 0
        self.inp = inp
        self.out = out
        self.fns = {}
        self.args = {}

        self.regsimple(lambda a,b,c: c.set(a.get()+b.get()), 1, 3),
        self.regsimple(lambda a,b,c: c.set(a.get()*b.get()), 2, 3),
        self.regsimple(lambda a: a.set(self.inp()), 3, 1),
        self.regsimple(lambda a: self.out(a.get()), 4, 1),

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

            self.ind += 1
            nargs = self.args[op]
            if self.ind + nargs > len(self.prog):
                return None
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

ogprog = [int(x) for x in input().split(',')]

def printBoard(board):
    xs = [key[0] for key in board]
    ys = [key[1] for key in board]
    for x in range(min(xs), max(xs)+1):
        rw = ""
        for y in range(min(ys), max(ys) + 1):
            rw += {0:' ', 1 : '#', 2 : '■', 3 : '■', 4: 'o' }[board[x,y]]
        print(rw)

def run(prog, quart):
    seq = 0
    x, y, id, scr = 0, 0, 0, 0
    bx, by = 0, 0
    px, py = 0, 0
    board = defaultdict(int)

    def inp():
        #printBoard(board)
        df = (by > py) - (by < py)
        return df

    def out(v):
        nonlocal seq, x, y, id, scr, bx, by, px, py
        if seq == 0:
            y = v
        elif seq == 1:
            x = v
        else:
            id = v
            if (y,x) == (-1,0):
                scr = v
            else:
                if v == 4:
                    bx, by = x, y
                if v == 3:
                    px, py = x, y
                board[x, y] = v
        seq = (seq + 1) % 3

    c = comp(prog, inp, out)
    c.prog[0] = quart
    c.run()
    return board, scr

def a(prog):
    board, _ = run(prog, prog[0])
    cnt = 0
    for v in board.values():
        if v == 2:
            cnt += 1
    return cnt


def b(prog):
    _, s = run(prog, 2)
    return s

print(a(ogprog))
print(b(ogprog))
