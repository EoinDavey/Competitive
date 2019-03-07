n = input()
x = map(int, raw_input().split())
y = map(int, raw_input().split())
t = 0

while x < y:
    x = map(lambda z:z+1,x)
    t+=1
print t
