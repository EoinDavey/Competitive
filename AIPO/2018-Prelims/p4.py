def cnt4(n):
    c = 0
    s = 0
    while(1):
        s = s*5 + 4
        if s > n:
            break
        c+=1
    return c

print(cnt4(int(input())))
