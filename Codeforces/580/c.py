import sys
n = int(input())
if n%2 == 0:
    print("NO")
    sys.exit(0)

ls = [0]*(2*n)
for i in range(n):
    u = i + n
    if i % 2 == 0:
        ls[i] = 2*i + 1
        ls[u] = 2*i + 2
    else:
        ls[i] = 2*i + 2
        ls[u] = 2*i + 1

print("YES")
print(' '.join(map(str, ls)))
