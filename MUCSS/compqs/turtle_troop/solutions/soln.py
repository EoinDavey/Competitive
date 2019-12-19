N, M = *map(int, input().split()),
ls = [int(x) for x in input().split()]
ls.sort(reverse=True)
ans = sum(ls[:M])
assert(ans > 0)
print(ans)
