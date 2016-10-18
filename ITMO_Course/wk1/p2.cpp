#include<cstdio>
#include<cstring>
#include<cmath>
#include<string>
#include<vector>
#ifdef JUDGE
#include<fstream>
#define print fprintf(fo,
#define scan fscanf(fi,
std::ifstream cin("aplusbb.in");
std::ofstream cout("aplusbb.out");
FILE * fi = fopen("aplusbb.in", "r");
FILE * fo = fopen("aplubb.out", "w");
#else
#include<iostream>
#define print printf(
#define scan scanf(
#endif

using namespace std;

int main(){
    long long int A, B;
    scan"%lld %lld", &A, &B);
    print"%lld\n", A+(B*B));
    return 0;
}
