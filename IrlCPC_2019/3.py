def anagram(s):
    freqs = {}
    for i in s:
        if i not in freqs:
            freqs[i] = 1
        else:
            freqs[i] += 1
    odd = 0
    for k, v in freqs.items():
        if v % 2 != 0:
            odd += 1
            if odd > 1:
                return False
    return True

def tolower(i):
    if (i >= 'A' and  i <= 'Z') :
        return chr(ord('a') + (ord(i) - ord('A')))
    return i


N = int(input())
ans = []
for i in range(N):
    stripped = []
    
    s = input() 
    for j in s: 
        if (j >= 'A' and  j <= 'Z') or (j >= 'a' and j <= 'z'):
            stripped.append(tolower(j))
    if anagram(stripped):
        ans.append(1)
    else:
        ans.append(0)

print(" ".join(list(map(str, ans))))
