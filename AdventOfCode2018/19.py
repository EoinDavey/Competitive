import sys
from collections import Counter, deque, defaultdict

def addr(reg, op):
    A, B, C = op
    reg[C] = reg[A] + reg[B]
    

def addi(reg, op):
    A, B, C = op
    reg[C] = reg[A] + B
    

def mulr(reg, op):
    A, B, C = op
    reg[C] = reg[A] * reg[B]
    

def muli(reg, op):
    A, B, C = op
    reg[C] = reg[A] * B
    

def banr(reg, op):
    A, B, C = op
    reg[C] = reg[A] & reg[B]
    

def bani(reg, op):
    A, B, C = op
    reg[C] = reg[A] & B
    

def borr(reg, op):
    A, B, C = op
    reg[C] = reg[A] | reg[B]
    

def bori(reg, op):
    A, B, C = op
    reg[C] = reg[A] | B
    

def setr(reg, op):
    A, B, C = op
    reg[C] = reg[A]
    

def seti(reg, op):
    A, B, C = op
    reg[C] = A
    

def gtir(reg, op):
    A, B, C = op
    reg[C] = 1 if  A > reg[B] else 0
    

def gtri(reg, op):
    A, B, C = op
    reg[C] = 1 if reg[A] > B else 0
    

def gtrr(reg, op):
    A, B, C = op
    reg[C] = 1 if reg[A] > reg[B] else 0
    

def eqir(reg, op):
    A, B, C = op
    reg[C] = 1 if A == reg[B] else 0

def eqri(reg, op):
    A, B, C = op
    reg[C] = 1 if reg[A] == B else 0

def eqrr(reg, op):
    A, B, C = op
    reg[C] = 1 if reg[A] == reg[B] else 0

#reg = [1] + [0]*5
reg = [0, 1, 10551282, 8, 0, 10551283]
ls = [line.strip() for line in sys.stdin]
prog = []

regI = 0
for l in ls:
    l = l.split()
    if l[0]=='#ip':
        regI = int(l[1])
    else:
        prog.append(l)

t = 0
ind = 9
while ind >= 0 and ind < len(prog):
    t += 1
    reg[regI] = ind
    l = prog[ind]
    if l[0] == 'addi':
        addi(reg, map(int, l[1:]))
    if l[0] == 'addr':
        addr(reg, map(int, l[1:]))
    if l[0] == 'setr':
        setr(reg, map(int, l[1:]))
    if l[0] == 'seti':
        seti(reg, map(int, l[1:]))
    if l[0] == 'mulr':
        mulr(reg, map(int, l[1:]))
    if l[0] == 'muli':
        muli(reg, map(int, l[1:]))
    if l[0] == 'eqrr':
        eqrr(reg, map(int, l[1:]))
    if l[0] == 'eqri':
        eqri(reg, map(int, l[1:]))
    if l[0] == 'eqir':
        eqir(reg, map(int, l[1:]))
    if l[0] == 'gtrr':
        gtrr(reg, map(int, l[1:]))
    if l[0] == 'gtri':
        gtri(reg, map(int, l[1:]))
    if l[0] == 'gtir':
        gtir(reg, map(int, l[1:]))
    ind = reg[regI] + 1
    print reg, ind
print reg[0]
