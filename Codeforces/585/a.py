def inp():return int(input())
a1 = inp()
a2 = inp()
k1 = inp()
k2 = inp()
n  = inp()

if k1 > k2:
    a1, a2 = a2, a1
    k1, k2 = k2, k1

a1so = min(a1, n//k1)

a2so = min(a2, (n - a1so*k1)//k2)

mx = a1so + a2so

totp = a1 * (k1 - 1) + a2 * (k2 - 1)
print(max(0, n - totp), mx)
