n = int(input())
scrs = [[int(x) for x in input().split()] for _ in range(n)]
scr_i = [sum(scrs[i]) for i in range(n)]
scr_i.sort(reverse=True)
print((sum(scr_i[:(n//2)]) - sum(scr_i[(n//2):]))//2)
