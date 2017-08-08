L=1
R=1000
while True:
    m = (L+R)/2;
    print m
    buff = raw_input();
    if buff=='lower':
        R = m-1
    elif buff=='higher':
        L= m+1
    else:
        exit(0)
