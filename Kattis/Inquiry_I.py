n = int(input())
xs = [int(input()) for _ in range(n)]

l_pref = [xs[0]]
s_pref = [xs[0]**2]
for x in xs[1:]:
  l_pref.append(l_pref[-1] + x)
  s_pref.append(s_pref[-1] + x**2)

mx = 0
for i in range(n):
  sq = s_pref[i]
  rst = l_pref[-1] - l_pref[i]
  mx = max(mx, sq*rst)
print(mx)
