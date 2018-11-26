// Convex hull trick, simpler if can sort insertions and queries
struct CvxHullTrickSimple {
    vector<ll> A;
    vector<ll> B;

    int ptr;

    cvxH():ptr(0){}

    // insert a descending
    void addLine(ll a, ll b){ // intersection of (A[len-2],B[len-2]) with (A[len-1],B[len-1]) must lie to the left of intersection of (A[len-1],B[len-1]) with (a,b)
        while (sz(A) >= 2 && (B[sz(B) - 2] - B[sz(B) - 1]) * (a - A[sz(A) - 1]) >= (B[sz(B) - 1] - b) * (A[sz(A) - 1] - A[sz(A) - 2])) {
            A.pop_back();
            B.pop_back();
        }
        A.pb(a);
        B.pb(b);
    }

    // query x ascending
    ll minValue(ll x) {
      ptr = min(ptr, sz(A) - 1);
      while (ptr + 1 < sz(A) && A[ptr + 1] * x + B[ptr + 1] <= A[ptr] * x + B[ptr]) {
        ++ptr;
      }
      return A[ptr] * x + B[ptr];
    }
};

struct CvxHullOpt {
    // Fully dynamic variant for use if can't guarantee
    // insertion or query order
    // stores lower envelope, negate lines and function to get upper
    static const ll qV = -(1LL<<50); //hacky special value
    struct line {
        ll a,b;
        mutable double xLeft;
        bool operator<(const line& l) const {
            if(l.a != qV)
                return a < l.a;
            return xLeft > l.xLeft;
        }
    };
    multiset<line> hull;

    ll xcomp(const line& a, const line& b, const line& c){
        //  < 0 => AxB < AxC
        //  > 0 => AxB > AxC
        return (a.a-c.a)*(b.b - a.b) - (c.b - a.b)*(a.a-b.a);
    }

    double xin(const line& a, const line& b){
        return (b.b - a.b)/(1.0*(a.a-b.a));
    }

    bool bad(set<line>::iterator y){
        auto z = next(y);
        if(y==hull.begin()){
            if(z==hull.end())
                return false;
            return y->a == z->a && y->b >= z->b;
        }
        auto x = prev(y);
        if(z==hull.end())
            return x->a == y->a && x->b <= y->b;
        return xcomp(*x, *y, *z) < 0;
    }

    void addLine(ll a, ll b){ // add line a*x + b
        CvxHullOpt::line l{a,b};
        auto y = hull.insert(l);
        if(bad(y)) { hull.erase(y); return;}
        while(next(y) != hull.end() && bad(next(y)))
            hull.erase(next(y));
        while(y!=hull.begin() && bad(prev(y)))
            hull.erase(prev(y));
        if(next(y)==hull.end())
            y->xLeft = -INF;
        else
            y->xLeft = xin(*y, *next(y));
        if(y != hull.begin())
            prev(y)->xLeft = xin(*prev(y), *y);
    }

    ll eval(ll x){
        auto l = hull.lower_bound({qV, 0, x});
        return l->a*x + l->b;
    }
};
