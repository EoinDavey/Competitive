def inp(): return int(input())

def solve():
    n, m, k = [int(x) for x in input().split()]
    h = [int(x) for x in input().split()]
    bg = m
    for i in range(n-1):
        tgt = max(0, h[i+1] - k)
        #print("Cur height:", h[i], "target:", tgt, "bg:", bg)
        if h[i] >= tgt:
            bg += h[i] - tgt
            continue
        if tgt-h[i] > bg:
            return False
        bg -= tgt-h[i]
    return True

for _ in range(inp()):
    if solve():
        print("YES")
    else:
        print("NO")
