n = int(input())
for i in range(3,n,4):
    print("aabb",end="")
print("aabb"[:n%4])
