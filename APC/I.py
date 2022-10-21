import sys

sys.setrecursionlimit(10**5)
N = int(input())
p = [int(x) for x in input().split()]

class Node:
    def __init__(self, xs, ys, p):
        self.p = p
        self.xrng = xs
        self.yrng = ys
        self.cs = []
        self.size = 0
        self.pts = []

    def insert(self, pt):
        if not (self.xrng[0] <= pt[0] <= self.xrng[1] and
                self.yrng[0] <= pt[1] <= self.yrng[1]):
            return

        self.size += 1

        if len(self.cs) > 0:
            for x in self.cs:
                x.insert(pt)
            return

        self.pts.append(pt)
        if len(self.pts) < 10:
            return
        # Split
        mdx = sum(self.xrng) // 2
        mdy = sum(self.yrng) // 2

        nd1 = Node((self.xrng[0], mdx), (self.yrng[0], mdy), self)
        nd2 = Node((self.xrng[0], mdx), (mdy+1, self.yrng[1]), self)
        nd3 = Node((mdx+1, self.xrng[1]), (mdy+1, self.yrng[1]), self)
        nd4 = Node((mdx+1, self.xrng[1]), (self.yrng[0], mdy), self)

        self.cs = [nd1, nd2, nd3, nd4]
        for p in self.pts:
            for c in self.cs:
                c.insert(p)
        self.pts = []

def getAll(root):
    o = []
    for c in root.cs:
        o += getAll(c)
    o += root.pts
    return o

def findClose(root, pt):
    if not (root.xrng[0] <= pt[0] <= root.xrng[1] and
            root.yrng[0] <= pt[1] <= root.yrng[1]):
        return None
    if root.size < 10:
        a = getAll(root)
        for x in a:
            if x != pt:
                return x
        return None
    for c in root.cs:
        fc = findClose(c, pt)
        if fc != None:
            return fc
    a = getAll(root)
    for x in a:
        if x != pt:
            return x
    return None

def findNode(root, pt):
    if not (root.xrng[0] <= pt[0] <= root.xrng[1] and
            root.yrng[0] <= pt[1] <= root.yrng[1]):
        return None
    if pt in root.pts:
        return root
    for c in root.cs:
        fc = findNode(c, pt)
        if fc != None:
            return fc
    return None

def remove(root, pt):
    if not (root.xrng[0] <= pt[0] <= root.xrng[1] and
            root.yrng[0] <= pt[1] <= root.yrng[1]):
        return
    root.size -= 1
    if pt in root.pts:
        root.pts.remove(pt)
        return
    for c in root.cs:
        remove(c, pt)

root = Node((0, 10**4 + 10), (0, 10**4 + 10), None)
pts = [(i+1, p[i]) for i in range(N)]
for p in pts:
    root.insert(p)

pt = (1, 1)
cst = 0
ln = 0
while ln < N:
    nxt = findClose(root, pt)
    print(nxt[0], nxt[1])
    dst = abs(nxt[0] - pt[0]) + abs(nxt[1] - pt[1])
    remove(root, nxt)
    pt = nxt
    ln += 1
