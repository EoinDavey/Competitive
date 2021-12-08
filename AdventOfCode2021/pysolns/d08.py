import sys

#  ttt 
# u   v
# u   v
# u   v
#  www
# x   y
# x   y
# x   y
#  zzz

def lines():
  return [line.strip() for line in sys.stdin]

inp = [[[set(y) for y in x.split()] for x in l.split(' | ')] for l in lines()]

def partA():
  print(len([x for _, b in inp for x in b if len(x) in [2,3,4,7]]))

lmp = {1: 2, 4: 4, 7: 3, 8: 7}

def partB():
  sm = 0
  for i, o in inp:
    # Find 1,4,7,8
    mp = {}
    for k,v in lmp.items():
      mp[k] = [x for x in i if len(x) == l][0]

    t = mp[7] - mp[1]
    uw = mp[4] - mp[1]
    mp[0] = [x for x in i if len(x) == 6 and len(uw - x) != 0][0]
    w = mp[8] - mp[0]
    u = uw - w
    mp[5] = [x for x in i if len(x) == 5 and len((t|u|w) - x) == 0][0]
    v = mp[1] - mp[5]
    y = mp[1] - v
    mp[9] = [x for x in i if x == (mp[5] | v)][0]
    z = mp[9] - (t|u|v|w|y)
    x = mp[8] - (t|u|v|w|y|z)
    mp[2] = t|v|w|x|z
    mp[3] = t|v|y|z|w
    mp[6] = t|u|w|x|y|z
    
    val = 0
    for x in o:
      val = 10*val
      for k,v in mp.items():
        if x == v:
          val += k
    sm += val
  print(sm)

partA()
partB()
