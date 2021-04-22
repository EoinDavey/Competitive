from collections import Counter


def test(s):
    return (
        len(s) == 6
        and s == "".join(sorted(s))
        and any(map(lambda x: x[1] == 2, Counter(s).most_common()))
    )


cnt = 0
L, R = (*map(int, input().split("-")),)

for i in range(L, R + 1):
    if test(str(i)):
        cnt += 1
print(cnt)
