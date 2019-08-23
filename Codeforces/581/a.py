import sys
s = int(raw_input(), 2)
if s <= 1:
    print 0
    sys.exit(0)
s -= 1
s = bin(s)[2:]

print (len(s) + 1)/2
