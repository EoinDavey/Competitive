package main

import (
	"fmt"
	"math/cmplx"
)

func main() {
	var x, y float64
	var r int
	cnt := 1
	for true {
		out := false
		_, err := fmt.Scanf("%f %f %d", &x, &y, &r)
		if err != nil {
			break
		}
		c := complex(x, y)
		z := complex(0, 0)
		for i := 0; i < r; i++ {
			if cmplx.Abs(z) > 2.0 {
				out = true
				break
			}
			z = cmplx.Pow(z, 2) + c
		}
		if out {
			fmt.Printf("Case %d: OUT\n", cnt)
		} else {
			fmt.Printf("Case %d: IN\n", cnt)
		}
		cnt++
	}
}
