/* c=a*b */
void mu(ll a[][NMAT], ll b[][NMAT], ll c[][NMAT], int _n) {
	for(int i=0;i<_n;i++)
		for(int j=0;j<_n;j++) {
			c[i][j]=0;
			for(int h=0;h<_n;h++) {
				c[i][j]+=(a[i][h]*b[h][j])%mod;
				c[i][j]%=mod;
			}
		}
}

/*returns ans=mat^b*/
void power(ll ans[][NMAT], ll mat[][NMAT], ll b, int _n) {
	ll tmp[NMAT][NMAT];
	for(int i=0;i<_n;i++)
		for (int j = 0; j<_n; j++)
			ans[i][j]=i==j;
	while(b) {
		if(b&1) {
			mu(ans, mat, tmp, _n);
			for(int i=0;i<_n;i++)
				for(int j=0;j<_n;j++)
					ans[i][j]=tmp[i][j];
		}
		mu(mat, mat, tmp, _n);
		for(int i=0;i<_n;i++)
			for(int j=0;j<_n;j++)
				mat[i][j]=tmp[i][j];
		b>>=1;
	}
}
