N = int(input())
ls = [int(x) for x in input().split()]

def mDiff(arr):
    mx = 0
    sm = 0
    for x in arr:
        if sm + x > 0:
            sm += x
        else:
            sm = 0
        mx = max(mx, sm)
    return mx

print(max(mDiff(ls), mDiff([-x for x in ls])))
