mvs = [[0, 1], [0, -1], [1, 0], [-1, 0], [1, 1], [1, -1], [-1, 1], [-1, -1]]
function readinp()
    inp = []
    while true
        l = readline()
        if l == ""
            break
        end
        push!(inp, [parse(Int, x) for x=chomp(l)])
    end
    return hcat(inp...)'
end

obrd = readinp()
H = size(obrd, 1)
W = size(obrd, 1)

function valid(pt)
    return 1 <= pt[1] <= H && 1 <= pt[2] <= W
end

function ns(pt)
    [pt + x for x=mvs if valid(pt + x)]
end

function flashprop(board)
    q = [[x,y] for x=1:H for y=1:W if board[x,y] > 9]
    s = Set()
    cnt = 0
    while length(q) > 0
        hd = pop!(q)
        if in(hd, s)
            continue
        end
        cnt += 1
        push!(s, hd)
        for n=ns(hd)
            board[n[1],n[2]] += 1
            if board[n[1], n[2]] > 9 && !in(n, s)
                push!(q, n)
            end
        end
    end
    return cnt
end

function procstep(board)
    for i=1:H
        for j=1:W
            board[i,j] += 1
        end
    end
    cnt = flashprop(board)
    for i=1:H
        for j=1:W
            if board[i,j] > 9
                board[i, j] = 0
            end
        end
    end
    return cnt
end

function part1()
    b = copy(obrd)
    sm = 0
    for i=1:100
        sm += procstep(b)
    end
    println(sm)
end

function part2()
    b = copy(obrd)
    stp = 0
    while true
        stp += 1
        procstep(b)
        all = true
        for i=1:H
            for j=1:W
                if b[i,j] != 0
                    all = false
                end
            end
        end
        if all
            break
        end
    end
    println(stp)
end

part1()
part2()
