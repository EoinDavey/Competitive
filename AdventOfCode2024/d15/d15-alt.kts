// This version has better worst-case performance, but is slower in reality
data class Vec(val x: Int, val y: Int) {
    operator fun plus(o: Vec) = Vec(x + o.x, y + o.y)
}

val MVS = arrayOf(Vec(-1, 0), Vec(0, 1), Vec(1, 0), Vec(0, -1))
fun charToMv(c: Char)
    = MVS[when(c){ '^' -> 0 '>' -> 1 'v' -> 2 else -> 3}]

typealias Grid = List<String>
typealias MutGrid = MutableList<MutableList<Char>>
fun MutGrid.h() = this.size
fun MutGrid.w() = this[0].size
operator fun MutGrid.get(v: Vec) = this[v.x][v.y]
operator fun MutGrid.set(v: Vec, c: Char){this[v.x][v.y] = c}

fun shift(st: MutGrid, mv: Vec, s: Vec): Boolean {
    val visOrd = mutableListOf<Vec>()
    fun check(): Boolean {
        val seen = mutableSetOf(s)
        visOrd.add(s)
        var qh = 0
        while(qh < visOrd.size){
            val u: Vec = visOrd[qh++]
            val nxt = u + mv
            if(st[nxt] == '#')
                return false
            if(nxt in seen)
                continue
            if(st[nxt] == '.')
                continue
            seen.add(nxt)
            visOrd.add(u + mv)
            val extra = when(st[nxt]){
                ']' -> nxt + charToMv('<')
                '[' -> nxt + charToMv('>')
                else -> null
            }
            extra?.takeIf{it !in seen}?.let{
                seen.add(it)
                visOrd.add(it)
            }
        }
        return true
    }
    if(!check())
        return false
    for(u in visOrd.asReversed()){
        st[u + mv] = st[u]
        st[u] = '.'
    }
    return true
}

fun solve(st: MutGrid, dirs: String): Int {
    var rp: Vec = (0..<st.h()).asSequence().flatMap{x ->
        (0..<st.w()).asSequence().filter{y -> st[x][y] == '@'}.map{y -> Vec(x, y)}
    }.first()

    for(mv in dirs.map{charToMv(it)}) {
        if(shift(st, mv, rp))
            rp += mv
    }
    return (0..<st.h()).sumOf{x ->
        (0..<st.w()).sumOf{y ->
            if(st[x][y] == 'O' || st[x][y] == '[')
                100 * x + y
            else
                0
        }
    }
}

fun partA(grid: Grid, dirs: String): Int {
    val st: MutGrid = grid.asSequence().map{it.toMutableList()}.toMutableList()
    return solve(st, dirs)
}

fun partB(grid: Grid, dirs: String): Int {
    val st: MutGrid = grid.asSequence().map{rw ->
        mutableListOf<Char>().apply{
            rw.forEach{c ->
                when(c) {
                    '@' -> {add('@'); add('.')}
                    'O' -> {add('['); add(']')}
                    else -> {add(c); add(c)}
                }
            }
        }
    }.toMutableList()
    return solve(st, dirs)
}

fun main() {
    val lines = generateSequence(::readlnOrNull).toList()
    val grid = lines.takeWhile{!it.isBlank()}
    val dirs = lines.takeLastWhile{!it.isBlank()}.joinToString("")
    println("Part A: ${partA(grid, dirs)}")
    println("Part B: ${partB(grid, dirs)}")
}
main()
