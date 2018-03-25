#include<bits/stdc++.h>
using namespace std;

ofstream outfile;
ifstream infile;

map<string,set<string> > descendants;
map<string, map<string,int> > depths;
set<string> names;
map<string,string> parent;
int N;
string a,b;

int main(){
    infile.open("family.in");
    outfile.open("family.out");
    infile >> N >> a >> b;
    string tmp1,tmp2;
    names.insert(a);
    names.insert(b);
    for(int i = 0; i < N; ++i){
        infile >> tmp1 >> tmp2;
        parent[tmp2] = tmp1;
        names.insert(tmp1);
        names.insert(tmp2);
    }
    for(const auto &name : names){
        int dpth = 0;
        string runner = name;
        for(;;){
            descendants[runner].insert(name);
            depths[runner][name] = dpth++;
            if(parent.count(runner) <= 0)
                break;
            runner = parent[runner];
        }
    }
    if(parent.count(a) > 0 && parent.count(b) > 0 && descendants[parent[a]].count(b) > 0 && descendants[parent[b]].count(a) > 0 && depths[parent[a]][b] != 0 && depths[parent[b]][a]!=0)
        outfile << "SIBLINGS" << endl;
    else if(descendants[a].count(b) > 0){
        // a d-mother of b
        int d = depths[a][b];
        outfile << a << " is the ";
        for(int i = d; i >= 2; --i){
            if(i==2)
                outfile << "grand-";
            else
                outfile << "great-";
        }
        outfile << "mother of " << b << endl;
    } else if(descendants[b].count(a) > 0){
        // b d-mother of a
        int d = depths[b][a];
        outfile << b << " is the ";
        for(int i = d; i >= 2; --i){
            if(i==2)
                outfile << "grand-";
            else
                outfile << "great-";
        }
        outfile << "mother of " << a << endl;
    } else if(parent.count(a) > 0 && descendants[parent[a]].count(b) > 0){
        // a d-aunt of b
        outfile << a << " is the ";
        int d = depths[parent[a]][b];
        for(int i = d; i >= 3; --i){
            outfile << "great-";
        }
        if(d==1)
            outfile << "sister";
        else 
            outfile << "aunt";
        outfile << " of " << b << endl;
    } else if(parent.count(b) > 0 && descendants[parent[b]].count(a) > 0){
        // a d-aunt of b
        outfile << b << " is the ";
        int d = depths[parent[b]][a];
        for(int i = d; i >= 3; --i){
            outfile << "great-";
        }
        if(d==1)
            outfile << "sister";
        else 
            outfile << "aunt";
        outfile << " of " << a << endl;
    } else {
        bool rel = false;
        for(const auto &name : names)
            if(descendants[name].count(a) > 0 && descendants[name].count(b) > 0)
                rel = true;
        if(rel)
            outfile << "COUSINS" << endl;
        else
            outfile << "NOT RELATED" << endl;
    }
    infile.close();
    outfile.close();
    return 0;
}
