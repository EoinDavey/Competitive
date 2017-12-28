def nxt((k,r),c):
    ch = chr((ord(c)-ord(k[0]))%26 + ord('A'))
    return k[1:]+[ch],r+[ch]

print "".join(reduce(nxt,raw_input(),(list(raw_input()),[]))[1])
