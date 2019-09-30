n = int(input())
inp = input()
f = inp[:n//2]
s = inp[n//2:]

fsm = sum([ord(x) - ord('0') if x != '?' else 0 for x in f])
ssm = sum([ord(x) - ord('0') if x != '?' else 0 for x in s])

diff = fsm - ssm

fcnt = f.count('?')
scnt = s.count('?')

blowupdiff, blowupf, blowups = diff, fcnt, scnt
shrinkdiff, shrinkf, shrinks = diff, fcnt, scnt

trn = True
for _ in range(fcnt+scnt):
    if trn: # Monocarp
        # Try blowup
        if blowupf:
            blowupf -= 1
            blowupdiff += 9
        else:
            blowups -= 1

        # Try shrink
        if shrinks:
            shrinks -= 1
            shrinkdiff -= 9
        else:
            shrinkf += 1

    else: # Bicarp
        # Fight blowup
        if blowups:
            blowups -= 1
            blowupdiff -= 9
        else:
            blowupf -= 1

        # Fight shrink
        if shrinkf:
            shrinkf -= 1
            shrinkdiff += 9
        else:
            shrinks -= 1

    trn = not trn

if blowupdiff == 0 or shrinkdiff == 0:
    print("Bicarp")
else:
    print("Monocarp")
