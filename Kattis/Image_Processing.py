H, W, N, M, = map(int, raw_input().split())
img = [map(int, raw_input().split()) for _ in xrange(H)]
ker = [map(int, raw_input().split()) for _ in xrange(N)]

ker = ker[::-1]
ker = map(lambda x: x[::-1], ker)

out = []
for i in xrange(H):
    if i + N > H:
        break
    o = []
    for j  in xrange(W):
        if j + M > W:
            break
        s = 0
        for x in xrange(N):
            for y in xrange(M):
                s+=ker[x][y] * img[i+x][j+y]
        o.append(s)
    out.append(o)

print '\n'.join(map(lambda x: ' '.join(map(str, x)),out))
