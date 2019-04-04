N, M  = map(int, input().split())
l1, l2 = input().split()
# M -= len(l1) + len(l2)
t1 = []
t2 = []
for i in l1:
    t1.append(int(i))
for i in l2:
    t2.append(int(i))

def updatet1(t1):
    global M
    l = len(t1)
    new_t1 = []
    last_tugging = t1[0] == 1
    if last_tugging and M > 0:
        new_t1.append(1)
        M -= 1
    for i, j in enumerate(t1):
        left = i - 1
        right = i + 1
        if (left >= 0 and right < l) and (j == 1 and t1[left] == 1 and t1[right] == 1):
            new_t1.append(0)
        elif j==1 and sum(t1[i-1:i+1]) <= 2:
            new_t1.append(1)
        elif (right < l) and (j == 0 and t1[right] == 1):
            new_t1.append(1)
        else:
            new_t1.append(0)
    return (new_t1, last_tugging)

def updatet2(t):
    new_t2, needs = (updatet1(t[::-1]))
    return (new_t2[::-1], needs)


used = 0
round_num = 0
score = 0
while True:
    s1 = sum(t1)
    s2 = sum(t2)
    if s1 > s2:
        score += s1 - s2
    elif s2 > s1:
        score -= s2 - s1
    #  print("T1 {}".format("".join(map(str, t1))))
    # print("T2 {}".format("".join(map(str, t2))))
    if score >= N:
        print("left " + str(round_num))
        break
    elif score <= -1*N:
        print("right " + str(round_num))
        break
    t1, t1needs = updatet1(t1)
    t2, t2needs  = updatet2(t2)
    round_num += 1
