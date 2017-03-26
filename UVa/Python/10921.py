while 1:
    try:
        a = int(input())
        b = int(input())
        print(a * b)
    except EOFError:
        break
