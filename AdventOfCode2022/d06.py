INP=input()

def findSeq(ln):
  s = []
  for i in range(len(INP)):
    s += INP[i]
    while len(s) > ln:
      s = s[1:]
    if len(set(s)) == ln:
      return i+1

def partA():
  print(findSeq(4))

def partB():
  print(findSeq(14))

partA()
partB()
