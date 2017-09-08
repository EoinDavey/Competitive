[R,C,Zr,Zc] = map(int,raw_input().split())

xss = reduce(lambda x,y: x + [y]*Zr,[reduce(lambda x,y: x + [y]*Zc, list(raw_input()),[]) for _ in range(R)], [] )

print "\n".join(map(lambda x: "".join(map(str,x)),xss))
