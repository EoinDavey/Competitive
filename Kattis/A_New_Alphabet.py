mp = ["@","8","(","|)","3","#","6","[-]","|","_|","|<","1",r"[]\/[]",r"[]\[]","0","|D","(,)","|Z","$","']['","|_|",r"\/",r"\/\/","}{","`/","2"]
def tn(x):
    c = ord(x)
    if c >= ord('A') and c <= ord('Z'):
        return mp[c-ord('A')]
    if c >= ord('a') and c <= ord('z'):
        return mp[c-ord('a')]
    return x

print "".join(map(tn,raw_input()))
