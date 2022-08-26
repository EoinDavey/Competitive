import sys

o = ""

for line in sys.stdin:
    line = line[:-1]

    if len(line)==0:
        continue

    if line[0] == '[':
        continue


    for x in line:
        if (x >= 'a' and x <= 'z') or (x >= '0' and x <= '9') or (x >= 'A' and x <= 'Z'):
            o += x

print o
