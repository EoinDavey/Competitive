str2num = {}
num2str = {}

def res(coms):
    global str2num,num2str
    exp=coms[1:len(coms)-1]
    for i,e in enumerate(exp):
        if e not in ['+','-','=']:
            if e in str2num:
                exp[i] = str(str2num[e])
            else:
                return " ".join(coms[1:]+["unknown"])

    ans = eval(" ".join(exp))
    if ans in num2str:
        return " ".join(coms[1:] + [str(num2str[ans])])
    return " ".join(coms[1:] + ["unknown"])

def main():
    global str2num,num2str
    while(True):
        try:
            coms = raw_input().split()
        except EOFError:
            break
        if coms[0]=="clear":
            str2num={}
            num2str={}
        elif coms[0]=="def":
            if coms[1] in str2num:
                del num2str[str2num[coms[1]]]
                del str2num[coms[1]]
            str2num[coms[1]]=int(coms[2])
            num2str[int(coms[2])]=coms[1]
        elif coms[0]=="calc":
            print res(coms)

main()
