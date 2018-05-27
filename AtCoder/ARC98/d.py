N = input()
As = map(int,raw_input().split())

msk = 0
sm = 0
l = 0
r = 0

while r < N:
    while As[r]&msk != 0:
        msk^=As[l]
        l+=1
    msk|=As[r]
    sm+=(r-l+1)
    r+=1
print sm
