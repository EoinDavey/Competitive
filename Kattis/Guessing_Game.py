h = []
l = []
while(True):
    g = int(raw_input())
    if g==0:
        break
    resp = raw_input()
    if resp=="too low":
        l.append(g)
    if resp=="too high":
        h.append(g)
    if resp=="right on":
        if all(map(lambda x: x < g,l)) and all(map(lambda x: x > g,h)):
            print "Stan may be honest"
        else:
            print "Stan is dishonest"
        l = []
        h = []
