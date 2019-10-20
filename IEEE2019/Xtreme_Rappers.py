def f(K, J, alpha, pr=False):
    A = K - 2*alpha
    B = J - alpha

    bet = min(A, B//2)

    if pr:
       return(alpha,bet)
    return alpha + bet

def srch(K, J):
    lo = 0
    hi = 10**15
    mx = 0
    while(hi - lo > 1):
        mid = (hi + lo)//2
        if (f(K, J, mid) > f(K, J, mid + 1)):
             hi = mid
        else:
             lo = mid

    a,b = f(K,J,lo+1,True)
    if a < 0 or b < 0:
        return 0
    return(max(0, f(K, J, lo+1)))

K, J = [int(x) for x in input().split()]
print(max(srch(K,J),srch(J,K)))
