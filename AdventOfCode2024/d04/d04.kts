operator fun <T, R> Iterable<T>.times(other: Iterable<R>): Sequence<Pair<T, R>>
    = this.asSequence().flatMap{a -> other.asSequence().map{b -> a to b}}

val MVS: List<Pair<Int, Int>>
    = ((-1..1) * (-1..1)).filter{it != Pair(0, 0)}.toList()

fun partA(lines: List<String>): Int {
    val h = lines.size
    val w = lines[0].length
    return ((0..<h)*(0..<w))
        .filter{(x, y) -> lines[x][y] == 'X'}
        .map{(x, y) ->
            MVS.filter{(dx, dy) -> x + 3 * dx in 0..<h && y + 3 * dy in 0..<w}
                .filter{(dx, dy) ->
                    ((0..3).map{lines[x + it * dx][y + it * dy]}.joinToString("") == "XMAS")
                }
                .count()
        }
        .sum()
}

fun partB(lines: List<String>): Int {
    val h = lines.size
    val w = lines[0].length
    return ((1..h-2) * (1..w-2))
        .filter{(x, y) -> lines[x][y] == 'A'}
        .filter{(x, y) -> setOf(lines[x - 1][y - 1], lines[x + 1][y + 1]) == setOf('M', 'S')}
        .filter{(x, y) -> setOf(lines[x + 1][y - 1], lines[x - 1][y + 1]) == setOf('M', 'S')}
        .count()
}

fun main() {
    val lines = generateSequence(::readlnOrNull).toList()
    println(partA(lines))
    println(partB(lines))
}

main()
