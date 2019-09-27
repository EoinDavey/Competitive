for _ in range(int(input())):
    st, inte, exp = *map(int,input().split()),
    if st + exp <= inte:
        print(0)
        continue

    l = max((st + inte + exp)//2 + 1, st)
    r = st + exp
    print(r - l + 1)
