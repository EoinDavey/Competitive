from random import randint, shuffle
import sys

TOT = randint(500, 1000)
M = randint(TOT//2, TOT)
print(TOT, M)
ls = [randint(-1000, 1000) for _ in range(TOT)]
print(' '.join(map(str, ls)))
