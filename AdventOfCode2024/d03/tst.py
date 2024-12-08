import sys

def lines():
  return [line.strip() for line in sys.stdin]

l = [c for line in lines() for c in line] + [None]
gen = iter(l)

state = 1
stck = [0]

while True:
  if state == 1:
    c = next(gen)
    if c == 'm':
      state = 3
    elif c == None:
      state = 2
    else:
      state = 1

  elif state == 2:
    print(stck[0])
    break

  elif state == 3:
    c = next(gen)
    if c == 'm':
      state = 3
    elif c == 'u':
      state = 4
    elif c == None:
      state = 2
    else:
      state = 1
  
  elif state == 4:
    c = next(gen)
    if c == 'm':
      state = 3
    elif c == 'l':
      state = 5
    elif c == None:
      state = 2
    else:
      state = 1

  elif state == 5:
    c = next(gen)
    if c == 'm':
      state = 3
    elif c == '(':
      state = 6
    elif state == None:
      state = 2
    else:
      state = 1 

  elif state == 6:
    c = next(gen)
    if c == 'm':
      state = 3
    elif '0' <= c <= '9':
      stck.append(ord(c)-ord('0'))
      state = 7
    elif c == None:
      state = 2
    else:
      state = 1

  elif state == 7:
    c = next(gen)
    if c == 'm':
      stck.pop()
      state = 3
    elif '0' <= c <= '9':
      stck.append(10 * stck.pop() + (ord(c) - ord('0')))
      state = 7
    elif c == ',':
      state = 8
    elif c == None:
      stck.pop()
      state = 2
    else:
      stck.pop()
      state = 1

  elif state == 8:
    c = next(gen)
    if c == 'm':
      stck.pop()
      state = 3
    elif '0' <= c <= '9':
      stck.append(ord(c)-ord('0'))
      state = 9
    elif c == None:
      stck.pop()
      state = 2
    else:
      stck.pop()
      state = 1

  elif state == 9:
    c = next(gen)
    if c == 'm':
      stck.pop()
      stck.pop()
      state = 3
    elif '0' <= c <= '9':
      stck.append(10 * stck.pop() + (ord(c) - ord('0')))
      state = 9
    elif c == ')':
      x = stck.pop()
      y = stck.pop()
      res = stck.pop()
      stck.append(res + x * y)
      state = 1
    elif c == None:
      stck.pop()
      stck.pop()
      state = 2
    else:
      stck.pop()
      stck.pop()
      state = 1
  else:
    assert(False)
