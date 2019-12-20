n = input()
if len(n) < 2:
    print(n)
else:
    if n[1] >= '5':
        print(''.join([str(int(n[0])+1)] + ['0']*(len(n)-1)))
    else:
        print(''.join([n[0]] + ['0']*(len(n)-1)))
