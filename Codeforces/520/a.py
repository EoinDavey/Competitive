n = input()
xs = map(int, raw_input().split())
xs = [0] + xs
xs.append(1001)
mx = 0
for i in xrange(1, len(xs)-1):
    for j in xrange(i, len(xs)-1):
        if xs[j+1] - xs[i-1] - 1 == j-i+1:
            mx = max(mx, j-i+1)
print mx
