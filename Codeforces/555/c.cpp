#include<bits/stdc++.h>
using namespace std;

const int MX_N = 200002;

int N;
int a[MX_N];

int main(){
    scanf("%d", &N);
    for(int i = 0; i < N; ++i){
        scanf("%d", a+i);
    }
    int left = 0;
    int right = N-1;
    int pv = 0;

    vector<char> out;

    while(right >= left){
        if(a[left] <= pv && a[right] <= pv){
            break;
        }
        if(a[left] > pv && a[right] <= pv){
            pv = a[left];
            left++;
            out.push_back('L');
        } else if(a[right] > pv && a[left] <= pv){
            pv = a[right];
            right--;
            out.push_back('R');
        } else if(a[right] == a[left]){
            int linc = 0;
            for(int x = left + 1; x <= right; ++x){
                if(a[x] <= a[x-1]){
                    break;
                }
                linc++;
            }
            int rinc = 0;
            for(int x = right - 1; x >= left; x--){
                if(a[x] <= a[x+1]){
                    break;
                }
                rinc++;
            }
            if(linc > rinc){
                pv = a[left];
                left++;
                out.push_back('L');
            } else {
                pv = a[right];
                right--;
                out.push_back('R');
            }
        } else { // a[right] > pv && a[left] > pv && a[left] != a[right]
            if(a[right] < a[left]){
                pv = a[right];
                right--;
                out.push_back('R');
            } else {
                pv = a[left];
                left++;
                out.push_back('L');
            }
        }
    }
    printf("%d\n", out.size());
    for(auto x : out) {
        printf("%c", x);
    }
    putchar('\n');
    return 0;
}
