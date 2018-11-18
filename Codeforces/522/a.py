from collections import Counter
def rls():
    return map(int, raw_input().split())

n, k = rls()
ls = rls()
c = Counter(ls)
mls = (c.most_common(1)[0][1] + (k-1))/k
s = set(ls)
pm = len(s)
print pm*k*mls - n 
