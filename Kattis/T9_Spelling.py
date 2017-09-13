k = {'a':'2',
        'b':'22',
        'c':'222',
        'd':'3',
        'e':'33',
        'f':'333',
        'g':'4',
        'h':'44',
        'i':'444',
        'j':'5',
        'k':'55',
        'l':'555',
        'm':'6',
        'n':'66',
        'o':'666',
        'p':'7',
        'q':'77',
        'r':'777',
        's':'7777',
        't':'8',
        'u':'88',
        'v':'888',
        'w':'9',
        'x':'99',
        'y':'999',
        'z':'9999',
        ' ':'0'}

def comb(x,y):
    if x[len(x)-1] == y[0]:
        return x+" " + y
    else:
        return x+y

def t9(s):
    return "".join(reduce(comb,map(lambda x: k[x],s[1:]),k[s[0]]))

N = int(raw_input())
for i in range(N):
    print ("Case #%d: " % (i+1)), t9(raw_input())
