from random import shuffle

ls = [i for i in range(10**4)]
shuffle(ls)
print(len(ls))
print(' '.join(str(x) for x in ls))
