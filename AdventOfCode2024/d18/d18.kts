val SIZE = 71

data class Vec(val x: Int, val y: Int){
    operator fun plus(o: Vec) = Vec(x + o.x, y + o.y)
}
val MVS = arrayOf(Vec(0, 1), Vec(0, -1), Vec(1, 0), Vec(-1, 0))

fun nbrs(u: Vec) = MVS.map{u + it}.filter{it.x in 0..<SIZE && it.y in 0..<SIZE}

fun solve(ps: List<Vec>, want: Int): Int? {
    val blocked = ps.take(want).toSet()
    val start = Vec(0, 0)
    val end = Vec(SIZE - 1, SIZE - 1)

    val dist = mutableMapOf<Vec, Int>(start to 0)
    val q = ArrayDeque<Vec>(listOf(start))
    while(!q.isEmpty()){
        val u = q.removeFirst()
        val d = dist[u]!!
        for(v in nbrs(u).filter{it !in blocked}.filter{it !in dist}){
            dist[v] = d + 1
            q.add(v)
        }
    }
    return dist[end]
}

fun partA(ps: List<Vec>) = solve(ps, 1024)

fun partB(ps: List<Vec>): String {
    var l = 1
    var r = ps.size
    while(l < r) {
        val md = (l + r) / 2
        if(solve(ps, md) == null) {
            r = md
        } else {
            l = md + 1
        }
    }
    val ans = ps[l - 1]
    return "${ans.x},${ans.y}"
}

fun main() {
    val lines: List<Vec> = generateSequence(::readlnOrNull)
        .map{it.split(",").map{it.toInt()}}
        .map{(a, b) -> Vec(a, b)}
        .toList()
    println("Part A: ${partA(lines)}")
    println("Part B: ${partB(lines)}")
}
main()
