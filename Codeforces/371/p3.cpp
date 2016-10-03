#include<iostream>
#include<cstdio>
#include<cstring>
#include<cmath>
#include<string>
#include<vector>
#include<map>

using namespace std;

map<int,int> multiset;

int main(){
    int T;
    cin >> T;
    char c;
    int in; 
    vector<int> set; 
    for(int t = 0; t < T; t++){
        do{
            scanf("%c",&c);
        }while(c=='\n');
        if(c!='?'){
            scanf("%d",&in);
            if(multiset[in]==0){
                set.push_back(in);
            }
            if(c=='+'){
                multiset[in]++;
            }else if(c=='-'){
                multiset[in]--;
            }
        } else {
            unsigned int w = 0;
            int msd = 0;
            do{
                scanf("%c",&c);
                if(c=='\n')break;
                if(c==' ')continue;
                w = (w<<1);
                if(c=='1')w++;
                msd++;
            }while(c!='\n');
            int cnt = 0;
            string cur;
            for(int i = 0; i < set.size(); i++){
                cur = to_string(set[i]);
                bool b = false;
                for(int j = max((int)cur.length(),msd)-1; j >=0; j--){
                    int k;
                    if(j>=cur.length())k=0;
                    else k = (int) cur[cur.length()-j-1]-'0';
                    if(((k&1)!=0) == (w&(1<<j)!=0));
                    else b = true;
                    printf("V:%d, j:%d, k:%d, b:%d\n",set[i],j,k,b);
                }
                if(!b)cnt++;
            }
            cout << cnt << endl;
        }
    }
    return 0;
}
