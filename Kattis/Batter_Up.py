input()
print (lambda xs:sum(xs)/(1.0*len(xs)))(filter(lambda d: d!=-1,map(int,raw_input().split())))
