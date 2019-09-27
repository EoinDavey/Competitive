for _ in range(int(input())):
    s = input()
    N = len(s)

    ons = [0]*N
    ons[0] = 1 if s[0] == '1' else 0

    for i in range(1, N):
        ons[i] = ons[i-1] + (1 if s[i] == '1' else 0)

    tot = 0

    for r in range(N):
        l = r
        pln = 0
        while l >= 0 and r - l < 32:
            ss = s[l:r+1]
            ln = int(ss, base=2)
            ones = ss.count('1')

            if ln <= pln:
                pln = ln
                l -= 1
                continue

            pln = ln

            st = r - ln + 1

            if st < 0:
                break

            cnt = ons[r] - (ons[st-1] if st - 1 >= 0 else 0)

            if cnt == ones:
                tot += 1

            l -= 1

    print(tot)
