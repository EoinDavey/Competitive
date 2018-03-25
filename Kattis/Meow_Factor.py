N = input()
x = 1
mx = 1
while x**9 <= N:
    if N%(x**9)==0:
        mx = x
    x+=1
print mx
