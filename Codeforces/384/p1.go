package main

import(
"fmt"
)

func main() {
    var n,a,b int
    fmt.Scanf("%d %d %d",&n,&a,&b)
    var s string
    fmt.Scan(&s)
    eq := s[a-1] == s[b-1]
    if eq {
        fmt.Println(0)
    } else {
        fmt.Println(1)
    }
}
