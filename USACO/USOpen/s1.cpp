#include<bits/stdc++.h>
using namespace std;

int main(){
    FILE *fin, *fout;
    fin = fopen("sort.in","r");
    fout = fopen("sort.out","w+");
    int N; fscanf(fin,"%d",&N);
    int A[N];
    for(int i = 0; i < N; ++i)
        fscanf(fin,"%d",A+i);
    int cnt = 0;
    bool sorted = false;
    while(!sorted){
        sorted=true;
        cnt++;
        for(int i = 0; i < N-1; ++i){
            if(A[i+1] < A[i]){
                int t = A[i+1];
                A[i+1] = A[i];
                A[i] = t;
                sorted=false;
            }
        }
    }
    fprintf(fout,"%d\n",cnt);
    fclose(fin);
    fclose(fout);
    return 0;
}
