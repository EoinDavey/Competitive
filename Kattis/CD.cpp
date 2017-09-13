#include<cstdio>
#include<unordered_set>
using namespace std;

int N,M,in;

int read_int(){
    char c;
    int out = 0;
    while(1){
        c = getchar_unlocked();
        if(c!=' '&&c!='\n')
            break;
    }
    do {
        out = out*10 + (c-'0');
        c = getchar_unlocked();
    }while(c!=' '&&c!='\n');
    return out;
}

int main(){
    while(true){
        N = read_int(); M = read_int();
        if(!N && !M)
            break;
        unordered_set<int> s1;
        for(int i = 0; i < N; i++)
            s1.insert(read_int());
        unordered_set<int> s2;
        for(int i = 0; i < M; i++)
            s2.insert(read_int());
        int cnt = 0;
        for(auto i = s1.begin(); i != s1.end(); i++)
            if(s2.find(*i)!=s2.end())
                cnt++;
        printf("%d\n",cnt);
    }
    return 0;
}
