data class Four(val a: Int, val b: Int, val c: Int, val d: Int)

val MOD = 16777216L

fun seq(code: Long) = sequence {
    var cur = code
    while(true){
        yield(cur)
        cur = (cur xor (cur * 64L)).mod(MOD)
        cur = (cur xor (cur / 32L)).mod(MOD)
        cur = (cur xor (cur * 2048L)).mod(MOD)
    }
}

fun changeSeq(code: Long) = seq(code).map{it.mod(10)}.zipWithNext(){a, b -> Pair(b, b - a)}

fun partA(codes: List<Long>) = codes.sumOf{seq(it).elementAt(2000)}

fun partB(codes: List<Long>): Int {
    val sums = mutableMapOf<Four, Int>()
    for(code in codes) {
        val q = ArrayDeque<Int>()
        val seen = mutableSetOf<Four>()
        for((price, delta) in changeSeq(code).take(2000)){
            q.add(delta)
            if(q.size > 4)
                q.removeFirst()
            if(q.size == 4) {
                val (a, b, c, d) = q.toList()
                val key = Four(a, b, c, d)
                if(key !in seen) {
                    seen.add(key)
                    sums[key] = (sums[key] ?: 0) + price
                }
            }
        }
    }
    return sums.maxOf{(_, v) -> v}
}

fun main() {
    val lines = generateSequence(::readlnOrNull).map{it.toLong()}.toList()
    println("Part A: ${partA(lines)}")
    println("Part B: ${partB(lines)}")
}
main()
