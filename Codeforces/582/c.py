def tensm(x):
    sm = sum([(x*y)%10 for y in range(1,11)])
    gp = x*10
    return sm, gp

for _ in range(int(input())):
    n, m = *map(int, input().split()),
    tsm, tgp = tensm(m)

    sm = tsm*(n//tgp)
    st = tgp*(n//tgp) + m
    while st <= n:
        sm += st % 10
        st += m
    print(sm)
