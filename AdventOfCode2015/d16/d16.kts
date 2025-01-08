val tape = mapOf(
    "children" to 3,
    "cats" to 7,
    "samoyeds" to 2,
    "pomeranians" to 3,
    "akitas" to 0,
    "vizslas" to 0,
    "goldfish" to 5,
    "trees" to 3,
    "cars" to 2,
    "perfumes" to 1,
)

fun partA(inp: List<Map<String, Int>>)
    = inp.indexOfFirst{sue -> tape.all{(k, v) -> sue.get(k)?.let{it == v} ?: true}} + 1

fun partB(inp: List<Map<String, Int>>)
    = inp.indexOfFirst{sue ->
        tape.all{(k, v) ->
            sue.get(k)?.let{
                when(k) {
                    "cats", "trees" -> it > v
                    "pomeranians", "goldfish" -> it < v
                    else -> it == v
                }
            } ?: true
        }
    } + 1

fun main(){
    val inp = generateSequence(::readlnOrNull)
        .map{it.dropWhile{it != ':'}.drop(2)}
        .map{it.split(", ").map{it.split(": ")}.map{(k, v) -> Pair(k, v.toInt())}.toMap()}
        .toList()
    println("Part A: ${partA(inp)}")
    println("Part B: ${partB(inp)}")
}
main()
