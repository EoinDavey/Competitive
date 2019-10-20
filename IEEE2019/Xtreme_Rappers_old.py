def solve(K, J):
    alph = 2*J - K
    if alph%3 != 0:
        return -1
    bet = 2*K - J
    if bet%3 != 0:
        return -1
    return alph//3 + bet//3


def srch(K, J):
    mx = 0
    for dj in range(10):
        for dk in range(10):
            nk = K - dk
            nj = J - dj
            if nk <= 0 or nj <= 0:
                continue
            mx = max(mx, solve(nk,nj))
    print(mx)

K, J = [int(x) for x in input().split()]
srch(K,J)
