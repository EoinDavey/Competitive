from collections import Counter
import sys

ls = [line for line in sys.stdin]
for i in xrange(len(ls)):
    for j in xrange(i+1, len(ls)):
        for x in xrange(len(ls[i])):
            if ls[i][:x] + ls[i][x+1:] == ls[j][:x] + ls[j][x+1:]:
                print ls[i][:x] + ls[i][x+1:]
