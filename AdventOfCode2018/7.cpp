#include<bits/stdc++.h>
using namespace std;

map<char, int> in; // keeps a count of the in-degree of each vertex in the graph
map<char, vector<char> > adjList; // for each vertex, store the list of neighbours (adjacency list)
set<char> chrs; // set of all letters

int main(){
    char u,v;
    while(scanf(" Step %c must be finished before step %c can begin.", &u, &v)==2){ // read in
        // edge goes from u to v
        
        in[v]+=1; // add 1 to in degree of v

        adjList[u].push_back(v); // Add v to adjacency list of u

        // Add u and v to set of all letters
        chrs.insert(u);
        chrs.insert(v);
    }

    priority_queue<char, vector<char>, greater<char>> q; // priority queue of available jobs

    // Add all jobs with 0 in degree i.e. we can start right away
    for(char i : chrs)
        if(in[i]==0)
            q.push(i);

    vector<char> out; //Store answer

    while(!q.empty()){ // while we still have some to process
        char c = q.top(); q.pop();
        out.push_back(c); // Add c to answer
        for(char i: adjList[c]){ // For every neighbour of c
            in[i]--; // decrease the in degree by 1
            if(in[i]==0) // if it's now 0, add it to the queue
                q.push(i);
        }
    }

    // print
    for(char c : out)
        printf("%c", c);

    putchar('\n');
    return 0;
}
