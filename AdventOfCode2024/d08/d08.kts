tailrec fun gcd(a: Int, b: Int): Int {
    if(b == 0)
        return a
    return gcd(b, a % b)
}
operator fun Pair<Int, Int>.plus(other: Pair<Int, Int>): Pair<Int, Int>
    = Pair(this.first + other.first, this.second + other.second)
operator fun Pair<Int, Int>.minus(other: Pair<Int, Int>): Pair<Int, Int>
    = Pair(this.first - other.first, this.second - other.second)

fun groupAnts(grid: List<String>): List<List<Pair<Int, Int>>> {
    return (0..<grid.size).asSequence()
        .flatMap{x -> (0..<grid[0].length).asSequence().map{y -> Pair(x, y)}}
        .filter{(x, y) -> grid[x][y] != '.'}
        .groupBy{(x, y) -> grid[x][y]}
        .values
        .toList()
}

fun partA(grid: List<String>): Int {
    val h = grid.size
    val w = grid[0].length
    val ants = groupAnts(grid)
    var anodes = mutableSetOf<Pair<Int, Int>>()
    val tryAdd: (Pair<Int,Int>) -> Unit
        = {if(it.first in 0..<h && it.second in 0..<w) anodes.add(it)}
    for(ls in ants) {
        for((i, p) in ls.withIndex()){
            for(j in i+1..<ls.size){
                val q = ls[j]
                val d = p - q
                tryAdd(p + d)
                tryAdd(q - d)
            }
        }
    }
    return anodes.size
}

fun partB(grid: List<String>): Int {
    val h = grid.size
    val w = grid[0].length
    val ants = groupAnts(grid)
    var anodes = mutableSetOf<Pair<Int, Int>>()
    for(ls in ants) {
        for((i, p) in ls.withIndex()){
            for(j in i+1..<ls.size){
                val q = ls[j]
                val dlta = p - q
                val g = gcd(dlta.first, dlta.second)
                val d = if (g != 0){
                    Pair(dlta.first / g, dlta.second / g)
                } else {
                    dlta
                }

                var wlk = p
                while((wlk.first in 0..<h && wlk.second in 0..<w)){
                    anodes.add(wlk)
                    wlk += d
                }
                wlk = p - d
                while((wlk.first in 0..<h && wlk.second in 0..<w)){
                    anodes.add(wlk)
                    wlk -= d
                }
            }
        }
    }
    return anodes.size
}

fun main() {
    val grid = generateSequence(::readlnOrNull).toList()
    println("Part A: ${partA(grid)}")
    println("Part B: ${partB(grid)}")
}
main()
