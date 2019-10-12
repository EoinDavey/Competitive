for _ in range(int(input())):
    sm = 0
    for _ in range(int(input())):
        input()
        sm += sum([int(x)-1 for x in input().split()])
    if (sm//2)%2:
        print("Alice")
    else:
        print("Bob")
