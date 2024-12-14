import kotlin.math.max

val H = 103
val W = 101

data class Vec(val x: Int, val y: Int) {
    operator fun plus(o: Vec) = Vec((x + o.x).mod(W), (y + o.y).mod(H))
    operator fun times(s: Int) = Vec((x * s).mod(W), (y * s).mod(H))
}

val MVS = arrayOf(Vec(0, 1), Vec(0, -1), Vec(1, 0), Vec(-1, 0),
    Vec(1, -1), Vec(-1, 1), Vec(1, 1), Vec(-1, -1))

fun partA(inp: List<Pair<Vec, Vec>>): Int {
    val turns = 100
    val ends = inp.map{(p, v) -> p + v * turns}
    val quads = arrayOf(0, 0, 0, 0)
    val mdy = H / 2
    val mdx = W / 2
    for((x, y) in ends){
        if(x == mdx || y == mdy)
            continue
        val a = if(2 * y < H) 0 else 1
        val b = if(2 * x < W) 0 else 1
        quads[2*a + b] += 1
    }
    return quads.fold(1, Int::times)
}

fun maxComp(ps: List<Vec>): Int {
    val psSet = ps.toSet()
    val seen = mutableSetOf<Vec>()
    fun walk(p: Vec): Int {
        seen.add(p)
        var sm = 1
        for(q in MVS.map{p + it}){
            if(q !in psSet)
                continue
            if(q in seen)
                continue
            sm += walk(q)
        }
        return sm
    }
    var mx = 0
    for(p in ps) {
        if(p in seen)
            continue
        mx = max(mx, walk(p))
    }
    return mx
}

fun partB(inp: List<Pair<Vec, Vec>>): Int {
    val (ps, vs) = inp.unzip()

    var st = ps
    var bst = 0
    var winTime = 0
    for(i in 1..10000){
        st = st.mapIndexed{i, p -> p + vs[i]}
        val mx = maxComp(st)
        if(mx > bst) {
            bst = mx
            winTime = i
        }
    }
    return winTime
}

fun main() {
    val int = Regex("-?[0-9]+")
    val inp: List<Pair<Vec, Vec>> = generateSequence(::readlnOrNull)
        .map{int.findAll(it).map{it.value.toInt()}.toList()}
        .map{(a, b, c, d) -> Pair(Vec(a, b), Vec(c, d))}
        .toList()
    println("Part A: ${partA(inp)}")
    println("Part B: ${partB(inp)}")
}
main()
