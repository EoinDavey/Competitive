import kotlin.math.min

val INF = 1_000_000

fun partA(strt: String, reps: List<Pair<String, String>>): Int {
    val mols = mutableSetOf<String>()
    for((a, b) in reps){
        val idxs = Regex(Regex.escape(a)).findAll(strt).map{it.range}.toList()
        for(idx in idxs){
            mols.add(strt.replaceRange(idx, b))
        }
    }
    return mols.size
}

fun topSortAllStrings(grph: Map<String, List<String>>): List<String> {
    val res = mutableListOf<String>()
    val vis = mutableSetOf<String>()
    fun insert(s: String){
        for(splt in 0..<s.length - 1){
            listOf(s.substring(0..splt), s.substring(splt+1..<s.length)).forEach{
                if(it !in vis){
                    vis.add(it)
                    insert(it)
                }
            }
        }
        grph[s]?.forEach{
            if(it !in vis){
                vis.add(it)
                insert(it)
            }
        }
        res.add(s)
    }
    grph.keys.forEach{
        if(it !in vis){
            vis.add(it)
            insert(it)
        }
    }
    return res
}

fun partB(tgt: String, reps: List<Pair<String, String>>): Int {
    val grph = reps.groupBy({it.first}, {it.second})
    val allStrings = topSortAllStrings(grph)
    val idx = allStrings.mapIndexed{i, x -> Pair(x, i)}.toMap()

    val table = Array(tgt.length + 1){Array(tgt.length){IntArray(allStrings.size){INF}}}
    for(len in 1..tgt.length) {
        for(strt in 0..tgt.length - len) {
            for(i in 0..<allStrings.size) {
                val s = allStrings[i]
                if(s.length > len) {
                    table[len][strt][i] = INF
                    continue
                }
                var bst = INF
                if(s.length == len && (0..<len).all{i -> s[i] == tgt[strt + i]})
                    bst = 0
                grph[s]?.forEach{r ->
                    bst = min(bst, 1 + table[len][strt][idx[r]!!])
                }
                for(s_splt in 0..<s.length - 1){
                    val head = idx[s.substring(0..s_splt)]!!
                    val tail = idx[s.substring(s_splt+1..<s.length)]!!
                    for(tgt_splt in 1..<len){
                        val res = table[tgt_splt][strt][head] + table[len - tgt_splt][strt + tgt_splt][tail]
                        bst = min(bst, res)
                    }
                }
                table[len][strt][i] = bst
            }
        }
    }
    return table[tgt.length][0][idx["e"]!!]
}

fun main(){
    val lines = generateSequence(::readlnOrNull).toList()
    val reps = lines.dropLast(2).map{it.split(" => ")}.map{(a, b) -> Pair(a, b)}
    val strt = lines.last()
    println("Part A: ${partA(strt, reps)}")
    println("Part B: ${partB(strt, reps)}")
}
main()
