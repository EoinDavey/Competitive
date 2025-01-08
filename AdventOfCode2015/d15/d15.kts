typealias Vec = IntArray
operator fun Vec.plus(o: Vec) = Vec(size){i -> this[i] + o[i]}
operator fun Vec.times(s: Int) = Vec(size){i -> this[i] * s}

fun solve(inp: List<Vec>, filter: (Vec) -> Boolean = {true}): Int {
    val n = inp.size
    val d = inp[0].size
    val stck = Vec(n){0}
    fun accum() = stck.zip(inp){a, b -> b * a}.reduce{a, b -> a + b}
    fun score(acc: Vec) = acc.dropLast(1).fold(1){a, b -> a * (b.takeIf{it > 0} ?: 0)}
    fun rec(p: Int, sm: Int): Int {
        if(p == n - 1) {
            stck[p] = 100 - sm
            val acc = accum()
            return if(filter(acc)) score(acc) else 0
        }
        val bst = (0..100-sm).maxOf{x ->
            stck[p] = x
            rec(p + 1, sm + x)
        }
        return bst
    }
    return rec(0, 0)
}

fun partA(inp: List<Vec>) = solve(inp)
fun partB(inp: List<Vec>) = solve(inp, {it.last() == 500})

fun main(){
    val int = Regex("-?[0-9]+")
    val inp = generateSequence(::readlnOrNull)
        .map{int.findAll(it).map{it.value.toInt()}.toList().toIntArray()}
        .toList()
    println("Part A: ${partA(inp)}")
    println("Part B: ${partB(inp)}")
}
main()
