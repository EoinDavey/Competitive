val MVS = arrayOf(Pair(-1, 0), Pair(0, 1), Pair(1, 0), Pair(0, -1))

fun posSequence(grid: List<String>, start: Pair<Int, Int>, extraBlock: Pair<Int, Int>? = null) : Sequence<Triple<Int, Int, Int>> {
    val h = grid.size
    val w = grid[0].length
    return sequence {
        var state = Triple(start.first, start.second, 0)
        while(true) {
            yield(state)
            val (x, y, dir) = state
            val (dx, dy) = MVS[dir]
            val nx = x + dx
            val ny = y + dy
            if(nx !in 0..<h || ny !in 0..<w) {
                break
            }
            state = if(grid[nx][ny] == '#' || Pair(nx, ny) == extraBlock){
                Triple(x, y, (dir + 1) % 4)
            } else {
                Triple(nx, ny, dir)
            }
        }
    }
}

fun partA(grid: List<String>, start: Pair<Int, Int>): Int {
    return posSequence(grid, start).map{(x, y, _) -> Pair(x, y)}.toSet().size
}

fun hasCycle(grid: List<String>, start: Pair<Int, Int>, extraBlock: Pair<Int, Int>): Boolean {
    val hareIt = posSequence(grid, start, extraBlock).iterator()
    val turtleIt = posSequence(grid, start, extraBlock).iterator()

    var hare = hareIt.next()
    hare = hareIt.next()
    var turtle = turtleIt.next()
    while(true) {
        if(hare == turtle)
            return true
        if(!hareIt.hasNext())
            return false
        hare = hareIt.next()
        if(!hareIt.hasNext())
            return false
        hare = hareIt.next()
        turtle = turtleIt.next()
    }
}

fun partB(grid: List<String>, start: Pair<Int, Int>): Int {
    return posSequence(grid, start).map{(x, y, _) -> Pair(x, y)}.distinct()
        .filter{it != start && hasCycle(grid, start, it)}.count()
}

fun main() {
    val grid: List<String> = generateSequence(::readlnOrNull).toList()
    val h = grid.size
    val w = grid[0].length
    val start = (0..<h).asSequence()
        .flatMap{x -> (0..<w).asSequence().filter{y -> grid[x][y] == '^'}.map{y -> Pair(x, y)}}
        .first()
    println("Part A: ${partA(grid, start)}")
    println("Part B: ${partB(grid, start)}")
}
main()
