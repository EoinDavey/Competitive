input()
xs = set([int(x) for x in input().split()])
print(" ".join(map(str,sorted(list(set(range(100)).difference(xs))))))
