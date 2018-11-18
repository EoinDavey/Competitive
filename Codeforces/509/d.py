n, h = map(int, raw_input().split())
invals = [map(int, raw_input().split()) for _ in xrange(n)]
invals = map(tuple, invals)
revInvals = invals[::-1]

egain= [0]*n
bgain= [0]*n

for i in xrange(n):
    (r,l) = revInvals[i]
    if i:
        b = revInvals[i-1][0]
    bgain[i] = (r-l) + egain[i]
