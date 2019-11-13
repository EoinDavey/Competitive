ss = input().split()
cyc = len(ss) - 1

n = int(input())
pool = []
for _ in range(n):
    pool.append(input())

t1 = []
t2 = []
team1 = True
start_pos = 0
while pool:
    end_pos = (start_pos + cyc) % len(pool)
    if team1:
        p = pool[end_pos]
        t1.append(pool[end_pos])
        pool.pop(end_pos)
    else:
        p = pool[end_pos]
        t2.append(pool[end_pos])
        pool.pop(end_pos)
    team1 = not team1
    start_pos = end_pos

print(len(t1))
print('\n'.join(t1))
print(len(t2))
print('\n'.join(t2))


