ll ncrmem[MX_N][MX_N];

ll ncr(int n, int r){
	if(n==0)
		return r==0;
	if(r==0)
		return 1;
	if(ncrmem[n][r] != -1)
		return ncrmem[n][r];
	return ncrmem[n][r] = ncr(n-1, r-1) + ncr(n-1, r);
}
