while True:
    x0 = raw_input()
    if x0 == 'END':
        break
    i = 1
    while True:
        x1 = str(len(x0))
        if x1==x0:
            print i
            break
        i+=1
        x0 = x1
