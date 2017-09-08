import sys
vowels = ['a','e','i','o','u']
S = raw_input()

while(len(S) > 0):
    sys.stdout.write(S[0])
    if S[0] in vowels:
        S = S[3:]
    else:
        S = S[1:]
print
