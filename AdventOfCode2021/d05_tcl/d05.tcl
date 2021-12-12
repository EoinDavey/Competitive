proc read_line {} {
    set chars [gets stdin line]
    if {$chars == -1} { return 0 }
    set x [split $line " "]
    set a [split [lindex "$x" 0] ","]
    set b [split [lindex "$x" 2] ","]
    return [list $a $b]
}

proc sign {x} {
    if {$x > 0} {return 1}
    if {$x == 0} {return 0}
    return -1
}

proc incr_array {arr key} {
    upvar $arr a
    if {![info exists a($key)]} {set a($key) 0}
    incr a($key)
}

proc countInters {ls} {
    foreach l $ls {
        set a [lindex $l 0]
        set b [lindex $l 1]
        # v = sign(b - a)
        set v [list [sign [expr {[lindex $b 0] - [lindex $a 0]}]] [sign [expr {[lindex $b 1] - [lindex $a 1]}]]]
        set pt [list [lindex $a 0] [lindex $a 1]]
        while {[lindex $pt 0] != [lindex $b 0] || [lindex $pt 1] != [lindex $b 1]} {
            incr_array hit $pt
            # pt = b + v
            set pt [list [expr {[lindex $pt 0] + [lindex $v 0]}] [expr {[lindex $pt 1] + [lindex $v 1]}]]
        }
        incr_array hit $pt
    }
    foreach {k v} [array get hit] {
        if {$v > 1} {incr cnt}
    }
    return $cnt
}

while true {
    set line [read_line]
    if {$line == 0} break
    lappend inp $line
    if {[lindex [lindex $line 0] 0] == [lindex [lindex $line 1] 0] || [lindex [lindex $line 0] 1] == [lindex [lindex $line 1] 1]} {
        lappend hvs $line
    }
}

puts "Part 1: [countInters $hvs]"
puts "Part 2: [countInters $inp]"
