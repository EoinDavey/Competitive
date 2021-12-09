USING: kernel prettyprint hash-sets sets sequences io splitting arrays ;
IN: d08

: readArr ( -- inp ) lines [ " | " split1 [ " " split ] bi@ 2array ] map ;

: is1478? ( set -- ? ) cardinality { 2 3 4 7 } in? ;
: find1478s ( all -- some ) [ is1478? ] filter ;
: partA ( -- ) readArr [ last find1478s length ] map sum . ;

partA

! acedgfb cdfbe gcdfa fbcad dab cefabd cdfgeb eafb cagedb ab | cdfeb fcadb cdfeb cdbaf
! be cfbegad cbdgef fgaecd cgeb fdcge agebfd fecdb fabcd edb | fdgacbe cefdb cefbgd gcbe
