import sys

def lines():
  return [line.strip() for line in sys.stdin]

INP = [l.split() for l in lines()]
ROCK,PAPER,SCISSORS=1,2,3
wnrs = {
    (ROCK, PAPER): PAPER, (PAPER, ROCK): PAPER,
    (ROCK, SCISSORS): ROCK, (SCISSORS, ROCK): ROCK,
    (PAPER, SCISSORS): SCISSORS, (SCISSORS, PAPER): SCISSORS,
}

def scr(me, opp):
  if me == opp:
    return 3 + me
  wnr = wnrs[(me, opp)]
  if wnr == me:
    return 6 + me
  return me

def partA():
  res = 0
  for opp, me in INP:
    res += scr(ord(me)-ord('X')+1, ord(opp)-ord('A')+1)
  print(res)

def partB():
  res = 0
  for opp, tgt in INP:
    opp = ord(opp)-ord('A')+1
    for me in [ROCK, PAPER, SCISSORS]:
      if tgt=='Y' and me==opp:
        res += scr(me, opp)
        break

      if me==opp:
        continue

      if tgt=='X' and wnrs[(me, opp)] == opp:
        res += scr(me, opp)
        break

      if tgt=='Z' and wnrs[(me, opp)] == me:
        res += scr(me, opp)
        break

  print(res)

partA()
partB()
