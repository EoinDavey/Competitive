s = input()
ans = ['Mike']*len(s)
mn = s[0]
for i in range(1, len(s)):
    ans[i] = 'Ann' if mn < s[i] else 'Mike'
    mn = min(mn, s[i])
print('\n'.join(ans))
