data class Op(val op: String, val inps: Pair<String, String>, val out: String)

fun topSort(ops: Map<String, Op>): List<String> {
    val seen = mutableSetOf<String>()
    val ord = mutableListOf<String>()
    fun f(op: String) {
        ops[op]?.let{
            listOf(it.inps.first, it.inps.second).filter{it !in seen}.forEach{
                seen.add(it)
                f(it)
            }
        }
        ord.add(op)
    }
    for((k, _) in ops){
        if(k in seen)
            continue
        f(k)
    }
    return ord
}

fun partA(inits: List<Pair<String, Boolean>>, ops: Map<String, Op>): Long {
    val ord = topSort(ops)

    val vals = inits.toMap().toMutableMap()
    for(k in ord) {
        ops[k]?.let{
            val a = vals[it.inps.first]!!
            val b = vals[it.inps.second]!!
            vals[k] = when(it.op){
                "OR" -> a || b
                "AND" -> a && b
                "XOR" -> a != b
                else -> throw Error("Invalid op")
            }
        }
    }
    return vals.filter{(k, _) -> k.startsWith('z')}.toList().sortedBy{it.first}.foldRight(0L){x, acc ->
        2L * acc + (if(x.second) 1L else 0L)
    }
}

fun main(){
    val lines = generateSequence(::readlnOrNull).toList()
    val inits = lines.takeWhile{!it.isEmpty()}.map{it.split(": ")}.map{Pair(it[0], it[1] == "1")}
    val ops = lines.takeLastWhile{!it.isEmpty()}
        .map{it.split(" ")}
        .map{(a, b, c, _, e) -> Op(b, Pair(a, c), e)}
        .map{Pair(it.out, it)}
        .toMap()
    println(ops.size)
    println("Part A: ${partA(inits, ops)}")
}
main()
