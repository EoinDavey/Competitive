def find(x1,y1,x2,y2,k):
    h = ((x2-x1+1)/2)
    if len(k)==0:
        return (x1,y1)
    if k[0]=='0':
        return find(x1,y1,x1+h-1,y1+h-1,k[1:])
    if k[0]=='1':
        return find(x1+h,y1,x2,y1+h-1,k[1:])
    if k[0]=='2':
        return find(x1,y1+h,x1+h-1,y2,k[1:])
    if k[0]=='3':
        return find(x1+h,y1+h,x2,y2,k[1:])
s = raw_input()
N = len(s)

f = find(0,0,(2**N)-1,(2**N)-1,s)
print N,f[0],f[1]
