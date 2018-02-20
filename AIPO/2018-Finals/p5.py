from functools import reduce
s = input()
N = int(input())
l = len(s)


ls = []
ln = 1

for i in range(l):
    if i+1 >= l or s[i] != s[i+1]:
        if s[i]=='X':
            ls.append(ln)
        ln = 0
    ln += 1
print(sum(sorted(ls)[:-N]))
