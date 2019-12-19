from random import randint, shuffle
import sys

if len(sys.argv) < 2 :
    sys.exit(1)

TOT = int(sys.argv[1])
TOT = randint(TOT // 2, 2 * TOT)
print(TOT)

ls = [randint(-1000, 1000) for _ in range(TOT)]
print(' '.join(map(str, ls)))
