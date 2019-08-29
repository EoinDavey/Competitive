n = int(input())
seq = input()
ls = [False]*10

for x in seq:
    if x == 'L':
        for i in range(10):
            if not ls[i]:
                ls[i] = True
                break
    elif x == 'R':
        for i in range(9, -1, -1):
            if not ls[i]:
                ls[i] = True
                break
    else:
        ls[int(x)] = False

print(''.join(map(lambda x: '1' if x else '0', ls)))
