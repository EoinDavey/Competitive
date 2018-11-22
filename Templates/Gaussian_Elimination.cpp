/*
 * mat is augmented matrix
 * e.g 3x + 4y = 2 is [3,4,2]
 */
void gauss(double mat[MX_N][MX_N+1], double ans[MX_N], int n){
    int i,j,k,l;double t;

    for(j = 0; j < n-1; ++j){
        l = j;
        for(i = j+1; i < n; ++i){
            if(fabs(mat[i][j]) > fabs(mat[l][j]))
                l=i;
        }
        for(k = j; k <= n; ++k)
            t=mat[j][k],mat[j][k]=mat[l][k],mat[l][k]=t;
        for(i = j+1; i < n; ++i)
            for(k = n; k >= j; --k)
                mat[i][k] -= mat[j][k] * mat[i][j] / mat[j][j];
    }

    for(j = n-1; j >= 0; --j){
        for(t=0.0, k = j+1;k<n;++k)
            t += mat[j][k] * ans[k];
        ans[j] = (mat[j][n] - t) / mat[j][j];
    }
}
