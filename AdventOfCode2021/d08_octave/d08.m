1; % Mark this as a script-file, not a function file (octave weirdness)

function cell = split2sets( l )
    cell = strsplit(l, " ");
    cell = cellfun(@unique, cell, "UniformOutput", false);
endfunction

function splt = splitInpLine( line )
    splt = strsplit(line, " | ");
    splt = cellfun(@split2sets, splt, "UniformOutput", false);
    splt = cell2struct(splt, { "in", "out" }, 2);
endfunction

function cnt = count1478( l )
    cnt = 0;
    for x = l,
        s = x{1};
        if ismember(length(s), [ 2 3 4 7 ])
            cnt++;
        endif
    end
endfunction

function part1( inp )
    sm = 0;
    for x = inp,
        l = x{1};
        sm += count1478(l.out);
    end

    printf("Part 1: %d\n", sm);
endfunction

function f = firstMatch(func, arr)
    for elt = arr,
        x = elt{1};
        if func(x)
            f = x;
            return
        endif
    end
endfunction

function part2(inp)
    sm = 0;
    for x = inp,
        l = x{1};

        mp = {};
        ls = arrayfun(@(x) firstMatch(@(y) length(y) == x, l.in), [ 2 3 4 7 ], "UniformOutput", false);
        mp{1} = ls{1};
        mp{7} = ls{2};
        mp{4} = ls{3};
        mp{8} = ls{4};
        t = setdiff(mp{7}, mp{1});
        uw = setdiff(mp{4}, mp{1});
        mp{10} = firstMatch(@(x) length(x) == 6 && length(setdiff(uw, x)) != 0, l.in);
        w = setdiff(mp{8}, mp{10});
        u = setdiff(uw, w);
        mp{5} = firstMatch(@(x) length(x) == 5 && length(setdiff(union(t,uw), x)) == 0, l.in);
        v = setdiff(mp{1}, mp{5});
        y = setdiff(mp{1}, v);
        mp{9} = union(mp{5},v);
        z = setdiff(mp{9}, unique([t u v w y]));
        x = setdiff(mp{8}, unique([t u v w y z]));
        mp{2} = unique([t v w x z]);
        mp{3} = unique([t v y z w]);
        mp{6} = unique([t u w x y z]);

        val = 0;
        for x = l.out,
            x = x{1};
            val *= 10;
            for k = 1:10,
                if strcmp(mp{k}, x) == 1
                    val += mod(k, 10) ;
                endif
            end
        end
        sm += val;
    end
    printf("Part 2: %d\n", sm)
endfunction

inp = strsplit(fileread("/code/d08_octave/d08.txt"), "\n") ;
inp(end) = [];
inp = cellfun("splitInpLine", inp, "UniformOutput", false);

part1(inp);
part2(inp);
