'''
Disorderly Escape
=================

Oh no! You've managed to free the bunny prisoners and escape Commander Lambdas exploding space station, but her team of elite starfighters has flanked your ship. If you dont jump to hyperspace, and fast, youll be shot out of the sky!

Problem is, to avoid detection by galactic law enforcement, Commander Lambda planted her space station in the middle of a quasar quantum flux field. In order to make the jump to hyperspace, you need to know the configuration of celestial bodies in the quadrant you plan to jump through. In order to do *that*, you need to figure out how many configurations each quadrant could possibly have, so that you can pick the optimal quadrant through which youll make your jump. 

There's something important to note about quasar quantum flux fields' configurations: when drawn on a star grid, configurations are considered equivalent by grouping rather than by order. That is, for a given set of configurations, if you exchange the position of any two columns or any two rows some number of times, youll find that all of those configurations are equivalent in that way - in grouping, rather than order.

Write a function solution(w, h, s) that takes 3 integers and returns the number of unique, non-equivalent configurations that can be found on a star grid w blocks wide and h blocks tall where each celestial body has s possible states. Equivalency is defined as above: any two star grids with each celestial body in the same state where the actual order of the rows and columns do not matter (and can thus be freely swapped around). Star grid standardization means that the width and height of the grid will always be between 1 and 12, inclusive. And while there are a variety of celestial bodies in each grid, the number of states of those bodies is between 2 and 20, inclusive. The solution can be over 20 digits long, so return it as a decimal string.  The intermediate values can also be large, so you will likely need to use at least 64-bit integers.

For example, consider w=2, h=2, s=2. We have a 2x2 grid where each celestial body is either in state 0 (for instance, silent) or state 1 (for instance, noisy).  We can examine which grids are equivalent by swapping rows and columns.

00
00

In the above configuration, all celestial bodies are "silent" - that is, they have a state of 0 - so any swap of row or column would keep it in the same state.

00 00 01 10
01 10 00 00

1 celestial body is emitting noise - that is, has a state of 1 - so swapping rows and columns can put it in any of the 4 positions.  All four of the above configurations are equivalent.

00 11
11 00

2 celestial bodies are emitting noise side-by-side.  Swapping columns leaves them unchanged, and swapping rows simply moves them between the top and bottom.  In both, the *groupings* are the same: one row with two bodies in state 0, one row with two bodies in state 1, and two columns with one of each state.

01 10
01 10

2 noisy celestial bodies adjacent vertically. This is symmetric to the side-by-side case, but it is different because there's no way to transpose the grid.

01 10
10 01

2 noisy celestial bodies diagonally.  Both have 2 rows and 2 columns that have one of each state, so they are equivalent to each other.

01 10 11 11
11 11 01 10

3 noisy celestial bodies, similar to the case where only one of four is noisy.

11
11

4 noisy celestial bodies.

There are 7 distinct, non-equivalent grids in total, so solution(2, 2, 2) would return 7.

Languages
=========

To provide a Java solution, edit Solution.java
To provide a Python solution, edit solution.py

Test cases
==========
Your code should pass the following test cases.
Note that it may also be run against hidden test cases not shown here.

-- Java cases -- 
Input:
Solution.solution(2, 3, 4)
Output:
    430

Input:
Solution.solution(2, 2, 2)
Output:
    7

-- Python cases -- 
Input:
solution.solution(2, 3, 4)
Output:
    430

Input:
solution.solution(2, 2, 2)
Output:
    7
'''
from collections import Counter
from math import factorial

def nperms(cyc):
    tot = 1
    rem = sum(cyc)
    for i in cyc:
        tot *= nck(rem, i) * factorial(i-1)
        rem -= i

    for a, b in Counter(cyc).most_common():
        tot /= factorial(b)
    return tot

def swapCols(l, r, board):
    for i in xrange(r-1, l-1, -1):
        for h in xrange(len(board)):
            board[h][i], board[h][i+1] = board[h][i+1], board[h][i]

def apP(hx, wx):
    h = sum(hx)
    w = sum(wx)
    board = [range(x*w, (x+1)*w) for x in xrange(h)]

    ph = 0
    for jmp in hx:
        r = ph + jmp-1
        board = board[:ph] + [board[r]] + board[ph:r] + board[r+1:]
        ph += jmp

    pw = 0
    for jmp in wx:
        r = pw + jmp-1
        swapCols(pw, r, board)
        pw += jmp

    return board

def cycCount(hx, wx):
    perm = apP(hx, wx)
    mp = {}
    for i in xrange(len(perm)):
        for j in xrange(len(perm[i])):
            nm = i * len(perm[i]) + j
            mp[nm] = perm[i][j]

    vis = set()
    def v(x):
        if x in vis:
            return 0
        vis.add(x)
        return 1 + v(mp[x])

    o = 0
    for x in mp:
        a = v(x)
        if a:
            o += 1

    return o

def solution(w, h, s):
    wp = parts(w)
    hp = parts(h)

    Gsz = factorial(w)*factorial(h)

    tot = 0
    for wx in wp:
        for hx in hp:
            cyc = cycCount(hx, wx)
            nwp = nperms(wx)
            nhp = nperms(hx)
            np = nhp * nwp

            tot += np * (s ** cyc)

    return str(tot/Gsz)


cmemo = {}
def nck(n, k):
    if n == 0:
        return k == 0
    if k == 0:
        return 1
    if (n, k) not in cmemo:
        cmemo[(n, k)] = nck(n-1, k-1) + nck(n-1, k)
    return cmemo[(n,k)]

def parts(n):
    o = []
    s = set()

    def rec(n):
        if n == 0:
            s.add(tuple(sorted(o)))
        for i in xrange(1, n+1):
            o.append(i)
            rec(n-i)
            o.pop()

    rec(n)
    return s
