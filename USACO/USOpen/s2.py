fin = open("lemonade.in","r")
fout = open("lemonade.out","w+")
N = int(fin.readline())
ws = sorted(map(int,fin.readline().split()),reverse=True)
ln = 0
for c in ws:
    if ln <= c:
        ln+=1
fout.write(str(ln)+"\n")
fin.close()
fout.close()
