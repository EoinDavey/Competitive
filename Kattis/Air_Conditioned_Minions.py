xs = [map(int,raw_input().split()) for _ in range(int(raw_input()))]

xs = sorted(xs, key=lambda x: (x[1],x[0]))

thresh = xs[0][1]
cnt = 1
for l, r in xs[1:]:
    if l > thresh:
        cnt+=1
        thresh = r

print cnt
