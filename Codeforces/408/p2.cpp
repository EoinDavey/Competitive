#include<cstdio>
#include<cstring>

using namespace std;

int main(){
    int n,m,k;
    int bone_pos = 1;
    scanf("%d %d %d",&n,&m,&k);
    bool holes[n+1];
    memset(holes,false,sizeof(holes));
    int im;
    for(int i = 0; i < m; i++){
        scanf("%d",&im);
        holes[im]=true;
    }
    bool dropped = false;
    if(holes[bone_pos])
        dropped = true;
    int iu,iv;
    for(int i = 0; i < k&&!dropped; i++){
        scanf("%d %d",&iu,&iv);
        if(iv==bone_pos){
            im = iv;
            iv = iu;
            iu = im;
        } else if (iu!=bone_pos)
            continue;
        bone_pos = iv;
        if(holes[iv])
            dropped = true;
    }
    printf("%d\n",bone_pos);
    return 0;
}
