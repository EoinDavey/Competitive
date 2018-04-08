xs = sorted(map(int,raw_input().split()))
print " ".join(map(str,[xs[ord(c)-ord('A')] for c in raw_input()]))
