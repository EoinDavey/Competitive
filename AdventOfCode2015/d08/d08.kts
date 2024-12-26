fun resolve(inp: String): Int {
    var i = 1
    var sm = 0
    while(i < inp.length && inp[i] != '"') {
        if(inp[i] != '\\'){
            sm += 1
            i++
        } else if(inp[i + 1] == 'x'){
            sm += 1
            i += 4
        } else {
            sm += 1
            i += 2
        }
    }
    return sm
}

fun encode(inp: String)
    = 2 + inp.sumOf(fun(c: Char): Int = when(c){
        '\\' -> 2
        '"' -> 2
        else -> 1
    })

fun partA(inps: List<String>) = inps.sumOf{it.length - resolve(it)}
fun partB(inps: List<String>) = inps.sumOf{encode(it) - it.length}

fun main(){
    val lines = generateSequence(::readlnOrNull).toList()
    println("Part A: ${partA(lines)}")
    println("Part B: ${partB(lines)}")
}
main()
