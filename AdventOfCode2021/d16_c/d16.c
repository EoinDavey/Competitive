#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>
#define BUF_SZ 2000
#define PCKT_BUF_SZ 10
#define INF 1000000000
#define ll long long int

char inp[BUF_SZ];

static inline int hexVal(char c) {
    if('0' <= c && c <= '9')
        return c - '0';
    return 10 + c - 'A';
}

struct parseState {
    int pos;
    size_t len;
    size_t val_len;
    char* vals;

    int vsum;
};

char bit_idx(struct parseState *state, int idx) {
    if(idx >= state->len)
        return -1;
    int vidx = idx / 8;
    int off = idx % 8;
    char hex = state->vals[vidx];
    return (hex & (1 << (7-off))) != 0 ? 1 : 0;
}

static inline char next(struct parseState *state) {
    return bit_idx(state, state->pos++);
}

ll read_n(struct parseState *state, int n) {
    ll sm = 0;
    for(int i = 0; i < n; i++)
        sm = 2 * sm + next(state);
    return sm;
}

ll read_pkt(struct parseState *state);

ll read_lit(struct parseState *state) {
    ll sm = 0;
    for(;;){
        ll rd = read_n(state, 5);
        sm = (sm << 4) | (rd & ((1<<4) - 1));
        if((rd & (1 << 4)) == 0)
            break;
    }
    return sm;
}

ll read_op(struct parseState *state, int t) {
    char lt = next(state);
    ll* vals = NULL;
    int idx = 0;
    if(lt == 0) {
        int sz = PCKT_BUF_SZ;
        vals = (ll*) malloc(sz * sizeof(ll));
        ll t_len = read_n(state, 15);
        int mrk = state->pos;
        while(state->pos < mrk+t_len){
            ll v = read_pkt(state);
            if(idx >= sz) {
                sz = 2*sz;
                vals = (ll*) realloc(vals, sz * sizeof(ll));
                if(vals == NULL){
                    fprintf(stderr, "Failed to realloc\n");
                    exit(1);
                }
            }
            vals[idx++] = v;
        }
    } else {
        ll n_sb = read_n(state, 11);
        vals = (ll*) malloc(n_sb * sizeof(ll));
        for(int i = 0; i < n_sb; i++) {
            ll v = read_pkt(state);
            vals[idx++] = v;
        }
    }
    int len = idx;
    ll ans = 0;
    switch(t) {
        case 0:
            for(int i = 0; i < len; i++)
                ans += vals[i];
            break;
        case 1:
            ans = 1;
            for(int i = 0; i < len; i++)
                ans *= vals[i];
            break;
        case 2:
            ans = INF;
            for(int i = 0; i < len; i++)
                ans = vals[i] < ans ? vals[i] : ans;
            break;
        case 3:
            for(int i = 0; i < len; i++)
                ans = vals[i] > ans ? vals[i] : ans;
            break;
        case 5:
            ans = vals[0] > vals[1] ? 1 : 0;
            break;
        case 6:
            ans = vals[0] < vals[1] ? 1 : 0;
            break;
        case 7:
            ans = vals[0] == vals[1] ? 1 : 0;
            break;
    }
    free(vals);
    return ans;
}

ll read_pkt(struct parseState *state) {
    ll v = read_n(state, 3);
    state->vsum += v;
    ll t = read_n(state, 3);
    if(t == 4)
        return read_lit(state);
    return read_op(state, t);
}

int main() {
    clock_t b = clock();
    if(fgets(inp, sizeof(inp), stdin) == NULL){
        fprintf(stderr, "Failed to read input\n");
        return 1;
    }
    int inplen = strlen(inp);
    if(inplen >= BUF_SZ - 1) {
        fprintf(stderr, "Buffer too small for whole line\n");
        return 1;
    }
    if(inp[inplen-1] == '\n')
        inp[inplen-- -1] == '\0';
    int vlen = (inplen+1)/2;
    char* vals = (char*) malloc(vlen * sizeof(char));
    memset(vals, 0, vlen);
    for(int i = 0; i < inplen; i++)
        vals[i/2] = vals[i/2] | (hexVal(inp[i]) << (i % 2 == 0 ? 4 : 0));
    struct parseState p = {0, 4*inplen, vlen, vals, 0};
    ll ans = read_pkt(&p);
    free(vals);
    clock_t e = clock();
    printf("Version sum: %d\nAns: %llu\n", p.vsum, ans);
    printf("Time elapsed: %f\n", (double)(e-b)/ CLOCKS_PER_SEC);
    return 0;
}
