BEGIN {
    FS=""
}
function toDec(arr, l,    i) {
    sm = 0
    for(i = 1; i <= l; i++) {
        pw = 2^(l - i)
        if(arr[i] == "1")
            sm += pw
    }
    return sm
}
{
    if(NF > L) { L = NF }
    for(i = 1; i <= NF; i++) {
        lines[NR][i] = $i
        if($i == "1"){
            ones[i] += 1
        } else {
            zeros[i] += 1
        }
    }
}
END {
    # part 1
    for(i = 1; i <= L; i++) {
        if(ones[i] > zeros[i])
            gamma[i] = "1" 
        else
            epsilon[i] = "1"
    }
    print toDec(gamma, L) * toDec(epsilon, L)

    # part 2
    for(l in lines) {
        keep[1][l] = 1
        keep[0][l] = 1
    }

    for(dpth = 1; dpth <= L; dpth++) {
        for(i = 0; i <= 1; i++) {
            onec[i] = 0
            zeroc[i] = 0
            alivec[i] = 0
        }
        for(l in lines) {
            for(i = 0; i <= 1; i++) {
                if(!keep[i][l])
                    continue
                alivec[i]++
                if(lines[l][dpth] == "1")
                    onec[i] += 1
                else
                    zeroc[i] += 1
            }
        }
        for(i = 0; i <= 1; i++) {
            if(alivec[i] <= 1)
                continue
            for(l in lines) {
                if(zeroc[i] > onec[i]) {
                    kill[0] = "1"
                    kill[1] = "0"
                } else {
                    kill[0] = "0"
                    kill[1] = "1"
                }
                if(lines[l][dpth] == kill[i])
                    keep[i][l] = 0
            }
        }
    }
    s = 1
    for(i = 0; i <= 1; i++)
        for(l in lines)
            if(keep[i][l])
                s *= toDec(lines[l], L)
    print s
}
