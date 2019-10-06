for _ in range(int(input())):
    N, K = [int(x) for x in input().split()]
    xs = [int(input()) for _ in range(N)]
    xs.sort()
    ivals = list(map(lambda x: x[1] - x[0], zip(xs, xs[1:])))
    ivals.sort()
    ans = sum(ivals[:N-K])
    print(ans)
