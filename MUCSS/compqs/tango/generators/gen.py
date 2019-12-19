from random import randint, shuffle
import sys

TOT = randint(500, 1000)
print(TOT)
ls = list(range(1, TOT+1))
shuffle(ls)
print(' '.join(map(str, ls)))
