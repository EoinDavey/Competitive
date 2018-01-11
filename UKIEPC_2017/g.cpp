#include<bits/stdc++.h>
using namespace std;

struct trip {
    int a,b,c;
    trip(int _a, int _b, int _c) : a(_a),b(_b),c(_c){}
    trip(){}
    bool operator== (const trip& p) const {
        return a==p.a && b==p.b && c==p.c;
    }
    bool operator!= (const trip& p) const {
        return !(*this == p);
    }
    trip operator+ (const trip& p) const {
        return trip(a+p.a,b+p.b,c+p.c);
    }
};

trip st1,st2,ed1,ed2;

trip moveTow(trip d, trip e){
    trip out(0,0,0);
    if(d.a!=e.a){
        out.a+=(d.a > e.a) ? -1 : 1;
    } else if(d.b!=e.b){
        out.b+=(d.b > e.b) ? -1 : 1;
    } else if(d.c!=e.c){
        out.c+=(d.c > e.c) ? -1 : 1;
    }
    return out;
}

trip moveRnd(){
    int dir = (rand() % 7);
    switch(dir){
        case 0:
            return trip(0,0,0);
        case 1:
            return trip(0,0,1);
        case 2:
            return trip(0,0,-1);
        case 3:
            return trip(0,1,0);
        case 4:
            return trip(0,-1,0);
        case 5:
            return trip(1,0,0);
        default:
            return trip(-1,0,0);
    }
}

int main(){
    scanf("%d %d %d %d %d %d",&st1.a,&st1.b,&st1.c,&ed1.a,&ed1.b,&ed1.c);
    scanf("%d %d %d %d %d %d",&st2.a,&st2.b,&st2.c,&ed2.a,&ed2.b,&ed2.c);
    while(st1!=ed1 || st2 != ed2){
        printf("(%d %d %d) (%d %d %d)\n",st1.a,st1.b,st1.c,st2.a,st2.b,st2.c);
        trip nst1 = st1+moveTow(st1,ed1);
        trip nst2 = st2+moveTow(st2,ed2);
        while(nst1 == nst2 || (nst1==st2 && nst2 == st1)){
            nst1 = st1+moveRnd();
        }
        st1=nst1;
        st2=nst2;
    }
    printf("(%d %d %d) (%d %d %d)\n",st1.a,st1.b,st1.c,st2.a,st2.b,st2.c);
    return 0;
}
