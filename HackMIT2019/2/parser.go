package main

import (
    "fmt"
    "io/ioutil"
    "bufio"
    "os"
    "strings"
    "golang.org/x/net/html"
)

const transcript = "procdtranscript.txt"

func main(){

    tF, err := ioutil.ReadFile(transcript)
    if err != nil {
        fmt.Printf("Failed to open file: %v\n", err)
        return
    }

    trans := string(tF)

    reader := bufio.NewReader(os.Stdin)

    z := html.NewTokenizer(reader)

    o := []string{}

    for cont := true; cont; {
        tt := z.Next()

        switch tt {
        case html.ErrorToken:
            cont = false
        case html.TextToken:
            s := string(z.Text())
            if len(s) == 1 {
                o = append(o, s)
            }
        case html.StartTagToken:
            bnm, has := z.TagName()
            nm := string(bnm)
            if len(nm) != 1  || !has {
                break
            }
            for m := true; m; {
                key, val, more := z.TagAttr()
                if !more {
                    m = false
                }

                skey, sval := string(key), string(val)
                if skey != "class" {
                    continue
                }

                ind := strings.Index(trans, sval)
                if ind == -1 {
                    fmt.Printf("%s not in transcript\n", sval)
                    continue
                }

            }
        }
    }

    fmt.Println(strings.Join(o, ""))

}
