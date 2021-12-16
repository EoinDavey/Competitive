USING: assocs kernel prettyprint hash-sets sets sequences io splitting arrays ;
USING: math namespaces hashtables ;
IN: d08_octave

SYMBOL: len-map
H{ { 1 2 } { 4 4 } { 7 3 } { 8 7 } } len-map set-global

: readArr ( -- inp ) lines [ " | " split1 [ " " split [ >hash-set ] map ] bi@ 2array ] map ;

: is1478? ( set -- ? ) cardinality { 2 3 4 7 } in? ;
: find1478s ( all -- some ) [ is1478? ] filter ;
: partA ( -- ) readArr [ last find1478s length ] map sum . ;

MAIN: partA
