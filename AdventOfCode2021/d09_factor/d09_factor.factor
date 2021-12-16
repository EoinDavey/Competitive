USING: arrays assocs formatting hashtables io io.encodings.utf8 io.files ;
USING: kernel math math.parser math.ranges math.vectors namespaces sequences ;
USING: sequences.product sorting strings ;
IN: d09_factor

: board-at ( board pt -- elt ) swap [ swap nth ] reduce ;
: inp>board ( lines -- board ) [ [ 1string string>number ] map >array ] map ;
: get-hw ( board -- h w ) [ length ] [ first length ] bi ;
: get-pts ( board -- pts ) get-hw [ [0,b) ] bi@ 2array <product-sequence> ;

SYMBOL: mvs
{ { 0 1 } { 1 0 } { -1 0 } { 0 -1 } } mvs set-global
: get-mvs ( -- mvs ) mvs get-global ;

: x ( pt -- x ) first ; inline
: y ( pt -- x ) last ; inline

: x-valid? ( board pt -- ? ) x swap length [ < ] curry [ 0 >= ] bi and ;
: y-valid? ( board pt -- ? ) y swap first length [ < ] curry [ 0 >= ] bi and ;
: valid? ( board pt -- ? ) [ x-valid? ] [ y-valid? ] 2bi and ;
: neighbours ( board pt -- ns ) [ v+ ] curry get-mvs swap map [ valid? ] with filter ;
: neighbour-vals ( board pt -- ns ) [ neighbours ] [ drop [ swap board-at ] curry ] 2bi map ;

: neighbours-lower? ( board pt -- ? ) [ neighbour-vals ] [ board-at [ > ] curry ] 2bi all? ;

: part-1 ( board -- ) [ get-pts ] keep
    [
        swap 2dup neighbours-lower?
        [ board-at 1 + ] [ 2drop 0 ] if
    ] curry map sum "Part 1: %d\n" printf ;

: should-visit? ( pt-val-pair colmap -- ? ) [ drop last 9 < ] [ [ first ] dip key? not ] 2bi and ;

:: flood ( board colmap c pt -- )
    ! Calculate ( pt, board[pt] ) list for all neighbs
    board pt [ neighbours ] [ neighbour-vals ] 2bi zip
    ! Filter to only positions we should visit
    colmap [ should-visit? ] curry filter [ first ] map
        ! Set each position to c in col map
        [ [ c swap colmap set-at ] each ]
        ! Call flood on each position
        [ [ '[ board colmap c _ flood ] call ] each ]
    bi ;

: flood-if-needed ( board colmap pt -- )
    ! Is pt = 9 or in colmap?
    3dup swap [ [ board-at 9 = ] keep ] dip key? or
    [
        3drop ! do nothing
    ] [
        ! Calculate new colour as size of existing colmap for convenience.
        [ [ assoc-size ] keep ] dip
        ! Set colmap[pt] = c
        swap 3dup set-at
        ! call flood
        -rot flood
    ] if ;

:: part-2 ( board -- )
    H{ } :> colmap
    board get-pts [ board colmap rot flood-if-needed ] each ! Flood every square
    colmap values H{ } [ [ inc-at ] curry each ] keep ! Count colours
    values natural-sort reverse 3 head product
    "Part 2: %d\n" printf ;

: run ( -- )
    "/factor/work/d09_factor/d09.txt" utf8
    [
        lines inp>board [ part-1 ] [ part-2 ] bi
    ] with-file-reader ;
MAIN: run
