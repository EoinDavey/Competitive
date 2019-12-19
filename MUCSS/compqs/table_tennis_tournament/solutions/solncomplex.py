for _ in range(int(input())):
    N = int(input())
    assert(33 <= N <= 200)
    scrs = [int(x) - 1 for x in input().split()]
    assert(len(scrs) == N)
    ind = 0

    def nextScore():
        global ind
        a = scrs[ind]
        ind += 1
        return a

    matches = [0, 0]
    ownr = -1
    while True:
        local = [0, 0]
        wnr = -1
        while True:
            local[nextScore()] += 1
            if local[0] > 10 and local[0] - local[1] >= 2:
                wnr = 0
                break
            if local[1] > 10 and local[1] - local[0] >= 2:
                wnr = 1
                break
        matches[wnr] += 1
        if matches[wnr] >= 3:
            ownr = wnr
            break

    assert(ind == N)
    print("Player %d wins" % (wnr + 1))
