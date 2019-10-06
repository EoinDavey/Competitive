INF = 10**10

def solve(cs):

    memo = {}

    def paint(i, b1, b2):
        # try b1

        if (i, b1, b2) in memo:
            return memo[(i, b1, b2)]

        if i >= len(cs):
            return 0

        mn = INF
        if b1 == cs[i]:
            mn = min(mn, paint(i + 1, b1, b2))
        else:
            mn = min(mn, 1 + paint(i + 1, cs[i], b2))

        if b2 == cs[i]:
            mn = min(mn, paint(i + 1, b1, b2))
        else:
            mn = min(mn, 1 + paint(i + 1, b1, cs[i]))

        memo[(i,b1,b2)] = mn
        return mn
    
    return paint(0, 0, 0)


for _ in range(int(input())):
    input()
    cs = [int(x) for x in input().split()]
    print(solve(cs))
