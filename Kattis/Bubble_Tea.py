N = input()
teaprcs = map(int,raw_input().split())
M = input()
topprcs = map(int,raw_input().split())
mn = 10**9
for i in range(N):
    ls = map(int,raw_input().split())[1:]
    for x in ls:
        mn = min(mn,teaprcs[i]+topprcs[x-1])
X = input()
print max(0,X/mn - 1)
