#include<cstdio>
#include<cstring>
#include<cmath>
#include<string>
#include<vector>
#include<iomanip>
#define FILE_IN "queue.in"
#define FILE_OUT "queue.out"
#ifdef JUDGE
#include<fstream>
std::ifstream cin(FILE_IN);
std::ofstream cout(FILE_OUT);
#else
#include<iostream>
#endif

using namespace std;

struct Node{
    long long int x;
    Node *next;
    Node *prev;
    Node(int in){
        x=in;
    }
};

Node *head = NULL;
Node *tail = NULL;
int size = 0;

void push(long long int v){
    Node *h = new Node(v);
    if(size==0){
        h->next = NULL;
        h->prev = NULL;
        head = h;
        tail = h;
    }else{
        h->next = head;
        head->prev = h;
        h->prev=NULL;
        head = h;
    }
    size++;
}

long long int pop(){
    long long int r = tail->x;
    Node *t = tail;
    if(size==1){
        tail=NULL;
    }else{
        tail = tail->prev;
        tail->next=NULL;
    }
    delete t;
    size--;
    return r;
}

int main(){
    int N;
    cin >> N;
    char c;
    long long int v;
    FILE *f = fopen(FILE_OUT,"w+");
    for(int i = 0; i<N; i++){
        cin >> c;
        if(c=='-'){
            fprintf(f,"%lld\n",pop());
        } else {
            cin >> v;
            push(v);
        }
    }
    return 0;
}
