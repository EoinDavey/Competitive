#include<bits/stdc++.h>
using namespace std;

const int MX_N = 200020;
char * buff;
int RA[MX_N],SA[MX_N],tempRA[MX_N],tempSA[MX_N],N,c[MX_N];

void countingSort(int k){
    int i,sum,maxi=max(300,N);
    memset(c,0,sizeof(c));
    for(i = 0; i < N; i++)
        c[i+k < N ? RA[i+k] : 0]++;
    for(i=sum=0; i < maxi; i++){
        int t = c[i];
        c[i]=sum;
        sum+=t;
    }
    for(i = 0; i < N; i++)
        tempSA[c[SA[i]+k < N ? RA[SA[i]+k]: 0]++] = SA[i];
    for(i=0; i < N;i++)
        SA[i]=tempSA[i];
}

int main(){
    buff = new char[100011];
    char * doubled = new char[MX_N];
    cin.getline(buff,MX_N);
    N=strlen(buff);
    for(int i = 0; i < N; i++)
        SA[i]=i,RA[i]=buff[i];
    int r;
    for(int k = 1; k < N; k <<= 1){
        countingSort(k);
        countingSort(0);
        tempRA[SA[0]]=r=0;
        for(int i = 1; i < N; i++){
            tempRA[SA[i]] = (RA[SA[i]]==RA[SA[i-1]] && RA[SA[i]+k]==RA[SA[i-1]+k] ? r:++r);
        }
        for(int i = 0; i < N; i++)
            RA[i]=tempRA[i];
    }
    delete buff;
    return 0;
}
