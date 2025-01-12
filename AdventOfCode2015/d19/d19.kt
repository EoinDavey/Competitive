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

var memo: Array<Array<MutableMap<String, Int>>> = emptyArray()
var tgt = ""
var grph: Map<String, List<String>> = mapOf()

fun f(s: String, strt: Int, end: Int): Int {
    if(s.length == end - strt + 1){
        for(i in 0..<s.length)
            if(s[i] != tgt[strt + i])
                return INF
        return 0
    }
    if(s.length > end - strt + 1){
        return INF
    }
    val memoised = memo[strt][end][s]
    if(memoised != null){
        return memoised
    }
    val reps = grph[s]
    if(reps != null){
        var bst = INF
        for(r in reps)
            bst = min(bst, 1 + f(r, strt, end))
        memo[strt][end][s] = bst
        return bst
    }
    if(s.length == 1){
        return INF
    }
    var bst = INF
    for(b_splt in 0..<s.length - 1){
        val head = s.substring(0..b_splt)
        val tail = s.substring(b_splt+1..<s.length)
        for(a_splt in strt..<end){
            val res = f(head, strt, a_splt) + f(tail, a_splt + 1, end)
            if(res < bst)
                bst = res
        }
    }
    memo[strt][end][s] = bst
    return bst
}

fun partB(inp: String, reps: List<Pair<String, String>>): Int {
    grph = reps.groupBy({it.first}, {it.second})
    memo = Array(inp.length){Array(inp.length){mutableMapOf<String, Int>()} }
    tgt = inp
    return f("e", 0, inp.length - 1)
}

fun main(){
    val lines = generateSequence(::readlnOrNull).toList()
    val reps = lines.dropLast(2).map{it.split(" => ")}.map{(a, b) -> Pair(a, b)}
    val strt = lines.last()
    println("Part A: ${partA(strt, reps)}")
    println("Part B: ${partB(strt, reps)}")
}
