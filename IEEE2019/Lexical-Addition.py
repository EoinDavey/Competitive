import sys
N, A, B = [int(x) for x in input().split()]
stp = B-A

for n in range(10**5):
    Bn = B*n
    diff = B*n - N
    if diff < 0:
        continue
    if diff == 0:
        print("YES")
        print(' '.join(map(str,[B]*n)))
        sys.exit(0)

    if stp == 0:
        continue

    nCh = diff/stp
    if nCh <= n:
        o = [B]*n
        i = 0
        while diff:
            drp = min(diff, stp)
            o[i] -= drp
            diff -= drp
            i += 1
        print("YES")
        print(' '.join(map(str,o)))
        sys.exit(0)

print("NO")
