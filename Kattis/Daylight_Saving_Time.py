def change(d,H,M):
    M+=d
    H+=M//60
    M%=60
    H%=24
    return (H,M)

for _ in range(int(input())):
    com = input().split()
    mul = -1 if com[0]=="B" else 1
    print(*change(int(com[1])*mul,int(com[2]),int(com[3])))
