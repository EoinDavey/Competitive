package main

import (
"fmt"
"math"
)

func pow(n,p uint64) uint64{
    return uint64(math.Pow(float64(n),float64(p)))
}

func main() {
    var i,n,k,ans uint64
    fmt.Scanf("%d %d",&n,&k)
    for i=1; i <= n; i++ {
        sP := pow(2,i-1)
        gap := k - sP
        if gap % pow(2,i) == 0 {
            ans = i
            break
        }
    }
    fmt.Println(ans)
}
