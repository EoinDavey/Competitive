import sys
from collections import defaultdict


def ris():
    return [int(x) for x in input().split()]


def ri():
    return [int(x) for x in input().split()]


def follow():
    cnt = defaultdict(lambda: 10 ** 100)
    s = set()
    ins = input().split(",")
    pos = (0, 0)
    t = 0
    for inst in ins:
        dist = int(inst[1:])
        if inst[0] == "U":
            for x in range(dist):
                t += 1
                pos = (pos[0] + 1, pos[1])
                cnt[pos] = min(cnt[pos], t)
                s.add(pos)
        if inst[0] == "R":
            for x in range(dist):
                t += 1
                pos = (pos[0], pos[1] + 1)
                cnt[pos] = min(cnt[pos], t)
                s.add(pos)
        if inst[0] == "D":
            for x in range(dist):
                t += 1
                pos = (pos[0] - 1, pos[1])
                cnt[pos] = min(cnt[pos], t)
                s.add(pos)
        if inst[0] == "L":
            for x in range(dist):
                t += 1
                pos = (pos[0], pos[1] - 1)
                cnt[pos] = min(cnt[pos], t)
                s.add(pos)
    return cnt, s


c1, s1 = follow()
c2, s2 = follow()
s1 &= s2
print("Part B:", min(map(lambda x: abs(x[0]) + abs(x[1]), s1)))
print("Part A:", min(map(lambda x: c1[x] + c2[x], s1)))
