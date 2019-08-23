for _ in range(int(input())):
    b, p, f = [int(x) for x in input().split()]
    h, c = [int(x) for x in input().split()]
    
    mx = 0
    brgs = 0
    while 2 * brgs <= b and brgs <= p:
        rmbns = b - 2*brgs
        chcks = min(rmbns//2, f)
        mx = max(mx, brgs * h + chcks * c)
        brgs+=1
    print(mx)
