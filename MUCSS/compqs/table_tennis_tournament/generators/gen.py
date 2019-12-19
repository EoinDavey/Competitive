from random import randint, random

T = randint(3, 10)

def playRandGame():
    scrs = []

    def nextScore():
        a = 0 if random() > 0.5 else 1
        scrs.append(a)
        return a

    matches = [0, 0]
    while True:
        local = [0, 0]
        wnr = -1
        while True:
            local[nextScore()] += 1
            if local[0] > 10 and local[0] - local[1] >= 2:
                wnr = 0
                break
            if local[1] > 10 and local[1] - local[0] >= 2:
                wnr = 1
                break
        matches[wnr] += 1
        if matches[wnr] >= 3:
            break

    print(len(scrs))
    print(' '.join(map(lambda x: str(x+1), scrs)))

print(T)
for _ in range(T):
    playRandGame()
