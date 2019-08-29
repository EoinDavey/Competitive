input()
a=*map(int, input().split()), 
s=sum(a)
print(["YES","NO"][s%2 or 2*max(a) > s])
