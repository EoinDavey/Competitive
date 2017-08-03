def proc(xs):
    v1 = "%d-%d" % (xs[0],xs[len(xs)-1])
    v2 = " ".join(str(x) for x in xs)
    return v1 if len(v1) < len(v2) else v2

N = int(raw_input())
xs = map(int,raw_input().split())
xs.sort()
run = [xs[0]]
prev = xs[0]
out = []

for x in xs[1:]:
    if x == prev+1:
        run.append(x)
    else:
        out.append(proc(run))
        run = [x]
    prev = x
out.append(proc(run))

print " ".join(out)
