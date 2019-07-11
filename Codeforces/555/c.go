package main

import (
    "fmt"
    "bufio"
    "os"
    "strconv"
)

const MX_N = 200002

var (
    N int
    a [MX_N]int
)

func reader() func() int {
    scn := bufio.NewScanner(os.Stdin)
    scn.Split(bufio.ScanWords)
    return func() int {
        scn.Scan()
        x, _ := strconv.Atoi(scn.Text())
        return x
    }
}

func main(){
    r := reader()
    N = r()
    for i := 0; i < N; i++ {
        a[i] = r()
    }
    left, right := 0, N-1
    pv := 0

    out := make([]rune, 0, N)
    for right >= left{
        if a[left] <= pv && a[right] <= pv {
            break
        }
        if a[left] > pv && a[right] <= pv {
            pv = a[left]
            left++
            out = append(out, 'L')
        } else if a[right] > pv && a[left] <= pv {
            pv = a[right]
            right--
            out = append(out, 'R')
        } else if a[right] == a[left] {
            linc := 1
            for x := left + 1; x <= right; x++ {
                if a[x] <= a[x-1] {
                    break
                }
                linc++
            }
            rinc := 1
            for x := right - 1; x >= left; x-- {
                if a[x] <= a[x+1] {
                    break
                }
                rinc++
            }
            if linc > rinc {
                pv = a[left]
                left++
                out = append(out, 'L')
            } else {
                pv = a[right]
                right--
                out = append(out, 'R')
            }
        } else { // a[right] > pv && a[left] > pv && a[left] != a[right]
            if a[right] < a[left] {
                pv = a[right]
                right--
                out = append(out, 'R')
            } else {
                pv = a[left]
                left++
                out = append(out, 'L')
            }
        }
    }
    fmt.Println(len(out))
    for _, x := range out {
        fmt.Printf("%c", x)
    }
    fmt.Println()
}
