fun height(lock: List<String>): List<Int> {
    val w = lock[0].length
    val h = lock.size
    return (0..<w).map{x -> (0..<h).map{y -> lock[y][x]}.takeWhile{it == '#'}.count() - 1}
}

fun overlap(key: List<Int>, lock: List<Int>)
    = key.zip(lock){a, b -> a + b}.any{it > 5}

fun main(){
    val lines = generateSequence(::readlnOrNull)
        .chunked(8)
        .map{if(it.last().isEmpty()) it.dropLast(1) else it}
        .toList()
    val (locks, keys) = lines.partition{it[0].all{it == '#'}}
    val lockHs = locks.map{height(it)}
    val keyHs = keys.map{height(it.reversed())}
    println("Part A: ${lockHs.sumOf{l -> keyHs.count{k -> !overlap(l, k)}}}")
}
main()
