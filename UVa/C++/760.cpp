#include<iostream>
#include<cstdio>
#include<cstring>
#include<string>
#include<vector>
#include<algorithm>

using namespace std;
const int mx_n = 700;

int N;
string S[mx_n];
int SA[mx_n],RA[mx_n],tempRA[mx_n],tempSA[mx_n],Phi[mx_n],LCP[mx_n],PLCP[mx_n],c[mx_n];
int k,aL;

string in;

void cntSort(int b){
    int mx = max(300,N);
    memset(c,0,sizeof(c));
    for(int i = 0; i < N; i++)
        c[(i+b<N) ? RA[i+b] : 0]++;
    int sum = 0;
    for(int i = 0; i < mx; i++){
        int t = c[i];
        c[i] = sum;
        sum+=t;
    }
    for(int i = 0; i < N; i++)
        tempSA[c[(SA[i]+b < N) ? RA[SA[i]+b] : 0]++] = SA[i];
    for(int i = 0; i < N; i++)
        SA[i] = tempSA[i];
}

void print(){
    for(int i =0; i < N; i++){
        printf("%d  %d  ",i,SA[i]);
        cout << S[SA[i]];
        printf("    %d  %d  %d\n",RA[SA[i]],RA[SA[i]+k],LCP[i]);
    }
    cout << endl;
}

int main(){
    string a,b;
    bool line = true;
    while(cin >> a >> b){
        a+='$';
        aL= a.length();
        b+='#';
        in =a + b;
        N = in.length();
        k=1;
        for(int i = 0; i < N; i++){
            S[i] = in.substr(i);
            SA[i] = i;
            RA[i] = (int) in[i];
        }
        for(k = 1; k < N; k<<=1){
            cntSort(k);
            cntSort(0);
            int r = 0;
            tempRA[SA[0]] = 0;
            for(int i = 1; i < N; i++){
                if(RA[SA[i]]==RA[SA[i-1]] && RA[SA[i]+k] == RA[SA[i-1]+k])
                    tempRA[SA[i]] = r;
                else tempRA[SA[i]] = ++r;
            }
            for(int i = 0; i < N; i++)
                RA[i] = tempRA[i];
        }
        Phi[SA[0]]=-1;
        for(int i = 1; i < N; i++)
            Phi[SA[i]] = SA[i-1];
        int L = 0;
        for(int i = 0; i < N; i++){
            if(Phi[i]==-1){
                PLCP[i] = 0;
                continue;
            }
            while(in[i+L] == in[Phi[i]+L])L++;
            PLCP[i] = L;
            L = max(L-1,0);
        }
        for(int i = 0; i < N; i++)
            LCP[i] = PLCP[SA[i]];
        int mx = 0;
        vector<int> spos;
        for(int i = 0; i < N-1; i++){
            if(SA[i] < aL-1 && SA[i+1] >= aL || SA[i] >= aL && SA[i+1] < aL -1){
                int m = LCP[i+1];
                if(m>mx){
                    spos.clear();
                    spos.push_back(i);
                    mx = m;
                } else if(m==mx && m > 0 && i != spos[spos.size()-1]+1){
                    spos.push_back(i);
                }
            }
        }
        if(!line){
            cout << endl;
        }
        line = false;
        vector<string> out;
        for(int i = 0; i < spos.size(); i++){
            out.push_back(in.substr(SA[spos[i]],mx));
        }
        sort(out.begin(),out.end());
        if(mx>0)cout << out[0] << endl;
        for(int i = 1; i < out.size(); i++){
            if(out[i]!=out[i-1])
                cout << out[i] << endl;
        }
        if(mx==0){
            cout << "No common sequence.\n";
        }
    }
    return 0;
}
