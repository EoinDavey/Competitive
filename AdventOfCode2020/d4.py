import sys
import re

def lines():
  return [line.strip() for line in sys.stdin]

inp = lines()

pps = []
pp = {}
for line in inp:
  if line == "":
    pps.append(pp)
    pp = {}
    continue
  pairs = [x.split(':') for x in line.split(' ')]
  for (a, b) in pairs:
    pp[a] = b
pps.append(pp)

req = ['byr', 'iyr', 'eyr', 'hgt', 'hcl', 'ecl', 'pid']

def validHgt(x):
  unit = x[-2:]
  num = int(x[:-2])
  if unit == "cm":
    return 150 <= num <= 193
  if unit == "in":
    return 59 <= num <= 76
  return False

def partA():
  cnt = 0
  for pp in pps:
    if all(map(lambda x: x in pp, req)):
      cnt += 1
  print(cnt)

def partB():
  validations = {
      'byr': lambda x: len(x) == 4 and 1920 <= int(x) <= 2002,
      'iyr': lambda x: len(x) == 4 and 2010 <= int(x) <= 2020,
      'eyr': lambda x: len(x) == 4 and 2020 <= int(x) <= 2030,
      'hgt': validHgt,
      'hcl': lambda x: re.fullmatch("^#[a-f0-9]{6}$", x) != None,
      'ecl': lambda x: x in ['amb', 'blu', 'brn', 'gry', 'grn', 'hzl', 'oth'],
      'pid': lambda x: re.fullmatch("^[0-9]{9}$", x) != None,
  }
  cnt = 0
  for pp in pps:
    if all(map(lambda x: x in pp and validations[x](pp[x]), req)):
      cnt += 1
  print(cnt)

partA()
partB()
