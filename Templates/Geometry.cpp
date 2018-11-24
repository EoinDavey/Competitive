typedef complex<double> pt;
typedef complex<double> vec;
typedef vector<pt> pgon;
typedef struct { pt p,q; } lseg;
struct circ{ pt c; double r; };
struct rect{ pt p,q;}; // X(p) <= X(q) and Y(p) <= Y(q)

double cross(const vec& a, const vec &b){
    return x(a)*y(b)-y(a)*x(b);
}
//cross product of (b-a) and (c-b), 0 is collinear
int orientation(const pt& a,
        const pt& b, const pt& c){
    double v = cross(b-a,c-b);
    if(abs(v-0.0)<EPS)
        return 0;
    return v > 0 ? 1 : 2;
}
//Line segment intersection
bool intersects(const lseg& a, const lseg& b){
    if(a.q == b.p || b.q == a.p)
        return false;
    if(orientation(a.p,a.q,b.p)
            !=orientation(a.p,a.q,b.q)
            && orientation(b.p,b.q,a.p)
            != orientation(b.p,b.q,a.q))
        return true;
    return false;
}
//Area of polygon
double area(const pgon& p){
    double area = 0.0;
    for(int i = 1; i < p.size(); ++i)
        area+=cross(p[i-1],p[i]);
    return abs(area)/2.0;
}
//If a->b->c is a counterclockwise turn
double ccw(const point& a, const point& b,
        const point& c){
    if(a==b || b==c || a==c)
        return false;
    point relA = b-a;
    point relC = b-c;
    return cross(relA,relC) >= 0.0;
}
//Returns if point p is in the polygon poly
bool inPoly(const pgon& poly, const pt& p){
    for(int i = 0; i < poly.size()-1; i++){
        if(!ccw(poly[i],p,poly[i+1]))
            return false;
    }
    return true;
}
//Distance from p to line (a,b)
double distToLine(const pt& p, const pt& a,
        const pt &b){
    vec ap = p-a;
    vec ab = b-a;
    double u = dot(ap,ab)/dot(ab,ab);
    //Ignore for non-line segment
    if(u < 0.0) //Closer to a
        return abs(a-p);
    if(u > 1.0) //Closer to b
        return abs(b-p);
    pt c = a+ab*u; // This is the point
    return abs(c-p);
}
//intersection pts of two circles
vector<pt> insct(const circ& a, const circ& b){
    vector<pt> o;
    double dist = abs(a.c - b.c);
    if(dist > a.r + b.r)
        return o; //none, don't touch
    if(abs(a.r-b.r) > dist)
        return o; //none, inside
    if(abs(dist - (a.r + b.r)) < EPS){ // one intersect
        pt p = a.c + (a.r/dist)*(b.c-a.c);
        o.pb(p);
        return o;
    }
    double delta = (sq(dist) + (a.r-b.r)*(a.r+b.r))/(2.0*dist);
    pt cent = a.c + (delta/dist)*(b.c-a.c);

    double h = sqrt(sq(a.r) - sq(delta));

    pt dVec = (b.c - a.c)/dist;
    o.pb(cent + h*pt(0,1)*dVec);
    o.pb(cent + h*pt(0,-1)*dVec);
    return o;
}

// intersection of two rectangles, sets none to true if no overlap
rect overlap(const rect& a, const rect& b, bool& none){
    rect r;
    if(X(a.p) > X(b.q) || Y(a.p) > Y(b.q)
        || X(b.p) > X(a.q) || Y(b.p) > Y(a.q)){
        none=true;
        return r;
    }
    r.p = {max(X(a.p),X(b.p)), max(Y(a.p),Y(b.p))};
    r.q = {min(X(a.q),X(b.q)), min(Y(a.q),Y(b.q))};
    return r;
}
