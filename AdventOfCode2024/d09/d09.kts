import java.util.TreeSet

data class Gap(val pos: Int, val sz: Int): Comparable<Gap> {
    override operator fun compareTo(other: Gap) = compareValues(pos, other.pos)
}
data class File(val pos: Int, val sz: Int, val id: Int)

fun partA(inp: List<Int>): Long {
    val ls = mutableListOf<Int>()
    inp.flatMapIndexedTo(ls) {i, x ->
        if(i % 2 == 0){
            List(x, {i / 2})
        } else {
            List(x, {-1})
        }
    }
    var l = (0..<ls.size).find{ls[it] == -1} ?: ls.size -1
    var r = (ls.size - 1 downTo 0).find{ls[it] != -1} ?: 0
    while(l < r) {
        val t = ls[l]
        ls[l] = ls[r]
        ls[r] = t
        while(l < ls.size && ls[l] != -1)
            l += 1
        while(r >= 0 && ls[r] == -1)
            r -= 1
    }
    return ls.foldIndexed(0){i, acc, x -> acc + (if(x != -1) (x * i).toLong() else 0)}
}

fun partB(inp: List<Int>): Long {
    var hd = 0
    val gaps = mutableListOf<Gap>()
    val files = mutableListOf<File>()
    for((i, x) in inp.withIndex()){
        if(i % 2 == 0) {
            files.add(File(hd, x, i / 2))
        } else {
            gaps.add(Gap(hd, x))
        }
        hd += x
    }

    val gapSets: List<TreeSet<Gap>> = List(10) { TreeSet() }
    for(gp in gaps)
        for(sz in (1..gp.sz))
            gapSets[sz].add(gp)
    for(i in files.size - 1 downTo 0){
        val file = files[i]

        if(gapSets[file.sz].size == 0)
            continue

        val gp = gapSets[file.sz].first()
        if(gp.pos > file.pos)
            continue

        val newGp = Gap(gp.pos + file.sz, gp.sz - file.sz)
        files[i] = File(gp.pos, file.sz, file.id)
        for(s in 1..gp.sz)
            gapSets[s].remove(gp)
        for(s in 1..newGp.sz)
            gapSets[s].add(newGp)
    }
    return files.fold(0){acc: Long, (pos, sz, id) ->
        //    Σi(0..sz-1) (pos + i) * id
        acc + id.toLong() * (pos * sz + (sz * (sz - 1)) / 2).toLong()
    }
}

fun main() {
    val inp = readln().map{it.code - '0'.code}
    println("Part A: ${partA(inp)}")
    println("Part B: ${partB(inp)}")
}
main()
