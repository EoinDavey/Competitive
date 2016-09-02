#include <stdio.h>
#include <iostream>
#include <string>
#include <sstream>
#include <cmath>
#include <climits>
#include <stdlib.h>
#include <vector>
#include <string.h>
#include <stack>
#include <algorithm>
using namespace std;

struct stretch{
	int x1;
	int y1;
	int l;
	int x2;
	int y2;
	bool operator <(const stretch& rhs){
		return x1 < rhs.x1;
	}
};

int main(){
	int m,n;
	cin >> n >> m;
	stretch ns[n];
	stretch ew[m];
	for(int i = 0; i < n; i++){
		stretch st;
		scanf("%d %d %d",&st.x1,&st.y1,&st.l);
		st.x2 = st.x1;
		st.y2 = st.y1 + st.l;
		ns[i] = st;
	}
	for(int i = 0; i < m; i++){
		stretch st;
		scanf("%d %d %d",&st.x1,&st.y1,&st.l);
		st.x2 = st.x1 + st.l;
		st.y2 = st.y1;
		ew[i] = st;
	}
	sort(ns,ns+n);
	sort(ew,ew+m);
	
	int max = 0;
	for(int i = 0; i < n;i++){
		stretch vert = ns[i];
		for(int j = 0;j<m && ew[j].x1 < vert.x1;j++){
			stretch hor = ew[j];
			//check if intersect
			if(vert.x1 > hor.x1 && vert.x1 < hor.x2 && vert.y1 < hor.y1 && vert.y2 > hor.y1){
				/*cout << "|(" << vert.x1 << "," << vert.y1 << ")(" << vert.x2 << "," << vert.y2 << ")|";
				cout << "|(" << hor.x1 << "," << hor.y1 << ")(" << hor.x2 << "," << hor.y2 << ")|" << endl;;*/
				int u,d,l,r;
				u=vert.y2 - hor.y1;
				d=hor.y1-vert.y1;
				l=vert.x1-hor.x1;
				r=hor.x2 - vert.x1;
				//cout << "u: " << u << " d: " << d << " l: " << l << " r: " << r << endl;
				int size = (u<d) ? u:d;
				size = (l<size)? l:size;
				size = (r<size)?r:size;
				max=(max>size) ? max:size;
			}
		}
	}
	cout << max << endl;
	
	return 0;
}