val SIZE = 71

data class Vec(val x: Int, val y: Int){
    operator fun plus(o: Vec) = Vec(x + o.x, y + o.y)
}
val MVS = arrayOf(Vec(0, 1), Vec(0, -1), Vec(1, 0), Vec(-1, 0))

fun nbrs(u: Vec) = MVS.map{u + it}.filter{it.x in 0..<SIZE && it.y in 0..<SIZE}

fun partA(ps: List<Vec>): Int? {
    val want = 1024
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

fun partB(ps: List<Vec>): String? {
    val ufdsGrid = Array(SIZE){arrayOfNulls<Vec>(SIZE)}
    fun get(u: Vec): Vec {
        ufdsGrid[u.x][u.y]?.let{
            val p = get(it)
            ufdsGrid[u.x][u.y] = p
            return p
        }
        return u
    }
    fun union(a: Vec, b: Vec) {
        val pa = get(a)
        val pb = get(b)
        if(pa != pb)
            ufdsGrid[pa.x][pa.y] = pb
    }
    val blockGrid = Array(SIZE){Array(SIZE){ps.size}}
    for((i, p) in ps.withIndex()){
        blockGrid[p.x][p.y] = i
    }
    for(x in 0..<SIZE) {
        for(y in 0..<SIZE) {
            if(blockGrid[x][y] != ps.size)
                continue
            val u = Vec(x, y)
            for(v in nbrs(u).filter{blockGrid[it.x][it.y] == ps.size})
                union(u, v)
        }
    }
    for(i in ps.size-1 downTo 0) {
        val p = ps[i]
        for(v in nbrs(p).filter{blockGrid[it.x][it.y] > i})
            union(p, v)
        if(get(Vec(0, 0)) == get(Vec(SIZE - 1, SIZE - 1)))
            return "${p.x},${p.y}"
    }
    return null
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
