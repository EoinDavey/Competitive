// a^b % md
ll modExp(ll a, int b, ll mod){
    if(b==0)
        return 1LL;
    if(b%2==0){
        ll y = modExp(a, b/2, mod);
        return (y*y)%mod;
    }
    return (a*modExp(a,b-1,mod))%mod;
}

// a*b^-1 % mod
// mod should be prime
ll modDiv(ll a, ll b, ll mod) {
    return (a * modExp(b, mod-2, mod))%mod;
}
