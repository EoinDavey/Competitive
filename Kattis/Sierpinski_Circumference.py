import sys
import math

ln = 1
for line in sys.stdin:
    n = float(line)
    res = int(math.floor((math.log(3,1.5)+n)/math.log(10,1.5)) + 1)
    print "Case %d: %d" % (ln,res)
    ln+=1
