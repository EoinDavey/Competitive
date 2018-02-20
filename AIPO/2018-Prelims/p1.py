nms = input().split()[1:]
rels = input().split()[1:]
print("\n".join(sorted(["%s, I am your %s." %(x,y) for x in nms for y in rels])))
