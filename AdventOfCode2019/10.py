import sys, math as m, itertools as i
u,l=[x.strip() for x in sys.stdin],len
H,W,S,p,r=l(u),l(u[0]),'Part',i.product,range
def R(a,b):g=m.gcd(a,b);return m.atan2((-1.0*b)/g,a/g)
M,X,Y=max([(l(set([R(a-x,b-y)for(a,b)in p(r(H),r(W))if(a,b)!=(x,y)and u[a][b]=='#'])),x,y)for(x,y)in p(r(H),r(W))if u[x][y]=='#'])
f=lambda x:R(x[0]-X,x[1]-Y)
pt=list(filter(lambda x:x,i.chain.from_iterable(i.zip_longest(*[list(x[1])for x in i.groupby(sorted([(a,b)for (a,b)in p(r(H),r(W))if(a,b)!=(X,Y)and u[a][b]=='#'],key=f),key=f)]))))[199]
print(S,'A',M,S,'B',pt[1]*100+pt[0])
