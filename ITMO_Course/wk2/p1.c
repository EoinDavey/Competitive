#define FILE_IN "stack.in"
#define FILE_OUT "stack.out"
#include<stdio.h>
#include<stdlib.h>

long long int *arr;
int arrSize = 0;
int size = 0;

void push(long long int v){
    if(arrSize <= size){
        arr = (long long int *) realloc(arr, 2*arrSize*sizeof(long long int));
        arrSize = arrSize<<1;
    }
    arr[size++] = v;
}

long long int pop(){
    long long int r = arr[--size];
    if(size < (1*arrSize)/3){
        arr = (long long int*) realloc(arr, (arrSize*sizeof(long long int))>>1);
        arrSize= arrSize>>1;
    }
    return r;
}

int main(){
    FILE *f = fopen(FILE_OUT,"w+");
    FILE *inf = fopen(FILE_IN,"r");
    int N;
    fscanf(inf,"%d",&N);
    char c;
    fscanf(inf,"%c",&c);
    long long int v;
    arr = (long long int *) malloc(sizeof(long long int));
    arrSize = 1;
    for(int i = 0; i<N; i++){
        fscanf(inf,"%c",&c);
        if(c=='-'){
            fprintf(f,"%lld\n",pop());
            fscanf(inf,"%c",&c);
        } else {
            fscanf(inf,"%lld",&v);
            fscanf(inf,"%c",&c);
            push(v);
        }
    }
    free(arr);
    return 0;
}
