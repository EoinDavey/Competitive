import kotlin.math.abs

data class Vec(val x: Int, val y: Int) {
    operator fun plus(o: Vec): Vec = Vec(x + o.x, y + o.y)
}

fun mvFromChar(c: Char) = when(c) {
    '^' -> Vec(-1, 0)
    'v' -> Vec(1, 0)
    '<' -> Vec(0, -1)
    '>' -> Vec(0, 1)
    else -> throw Error("Invalid char")
}

fun numpadPos(c: Char) = when(c) {
    'A' -> Vec(3, 2)
    '0' -> Vec(3, 1)
    else -> (c.code - '0'.code - 1).let{Vec(2 - (it / 3), it % 3)}
}

fun dirpadPos(c: Char) = when(c) {
    'A' -> Vec(0, 2)
    '^' -> Vec(0, 1)
    '<' -> Vec(1, 0)
    'v' -> Vec(1, 1)
    else -> Vec(1, 2)
}

fun getValidSeqs(a: Char, b: Char, posFunc: (Char) -> Vec, banned: Vec): List<String> {
    val ap = posFunc(a)
    val bp = posFunc(b)
    val ud = (if(bp.x < ap.x) "^" else "v").repeat(abs(ap.x - bp.x))
    val lr = (if(bp.y < ap.y) "<" else ">").repeat(abs(ap.y - bp.y))
    return listOf(ud + lr + "A", lr + ud + "A")
        .filter{banned !in it.dropLast(1).runningFold(ap){w, c -> w + mvFromChar(c)}}
}

fun numpadSeq(a: Char, b: Char) = getValidSeqs(a, b, ::numpadPos, Vec(3, 0))
fun dirpadSeq(a: Char, b: Char) = getValidSeqs(a, b, ::dirpadPos, Vec(0, 0))

fun solveCode(code: String, numRobots: Int, memo: MutableMap<Pair<String, Int>, Long>): Long {
    fun f(seq: String, dpth: Int): Long {
        if(dpth == numRobots)
            return seq.length.toLong()
        val key = Pair(seq, dpth)
        memo.get(key)?.let{
            return it
        }
        var w = 'A'
        var sm = 0L
        var seqFunc = if(dpth == 0) ::numpadSeq else ::dirpadSeq
        for(c in seq) {
            sm += seqFunc(w, c).map{f(it, dpth + 1)}.min()
            w = c
        }
        memo[key] = sm
        return sm
    }
    return f(code, 0)
}

fun solve(codes: List<String>, numRobots: Int): Long {
    val int = Regex("[0-9]+")
    val memo = mutableMapOf<Pair<String, Int>, Long>()
    return codes.sumOf{solveCode(it, numRobots, memo) * int.find(it)!!.value.toLong()}
}

fun main(){
    val codes = generateSequence(::readlnOrNull).toList()
    println("Part A: ${solve(codes, 3)}")
    println("Part B: ${solve(codes, 26)}")
}
main()
