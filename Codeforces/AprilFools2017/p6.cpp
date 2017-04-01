#include<iostream>
#include<cstdio>
#include<algorithm>
#include<unistd.h>

/* This is the greatest sorting function ever created by man */

using namespace std;

int main(){
    int N; cin >> N;
    int mxn = 10;
    int a[mxn];
    int p[] = {1,2,3,4,5,6,7,8,9,10,11,12};
    int dif[mxn];
    int out[mxn];
    for(int i = 0; i < N; i++)
        scanf("%d",&a[i]);
    for(int i = N; i < mxn; i++)
        a[i] = -i;
    sort(a,a+mxn); // Check answer ahead of time
    for(int i = 0; i < mxn; i++)
        dif[i] = p[i] - a[i]; //Generate difference array (DP)
    do{
        bool b = false;
        for(int i = 1; i < 50; i++) // 50 times to be really sure
            for(int j = 1; j < mxn; j++) 
                if(p[j] < p[j-1]) // make sure descending order
                    b = true;
        if(!b)
            for(int i = 0; i < mxn; i++)
                out[i] = p[i]; 
    }while(next_permutation(p,p+mxn)); // Check every permutation of ordering
    for(int i =0; i < mxn; i++)
        if((out[i]-dif[i])>0)
            printf(((i==mxn-1)?"%d":"%d "),out[i]-dif[i]);
    cout << endl;
    return 0;
}
