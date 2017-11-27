input()
print (lambda s:str(sum(s[::2])) + " " + str(sum(s[1::2])))(sorted(map(int,raw_input().split()))[::-1])
