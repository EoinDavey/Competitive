fun hasRun(s: List<Char>)
    = (0..<s.size-2).any{i -> s[i + 1] == s[i] + 1 && s[i + 2] == s[i + 1] + 1}

fun hasPairs(s: List<Char>): Boolean {
    val ls = (0..<s.size-1).filter{s[it] == s[it + 1]}
    return ls.size > 0 && ls.last() > ls.first() + 1
}

fun valid(s: List<Char>) = hasRun(s) && 'i' !in s && 'l' !in s && 'o' !in s && hasPairs(s)

fun next(inp: String): String {
    val stack = mutableListOf<Char>()
    fun srch(pos: Int, stack: MutableList<Char>): Boolean {
        if(pos == inp.length)
            return valid(stack) && (0..<inp.length).any{stack[it] != inp[it]}
        val released = stack.zip(inp.asIterable()).any{(a, b) -> a > b}
        val strt = if(released) 'a' else inp[pos]
        for(c in strt..'z') {
            if(c == 'i' || c == 'l' || c == 'o')
                continue
            stack.add(c)
            if(srch(pos + 1, stack))
                return true
            stack.removeLast()
        }
        return false
    }
    srch(0, stack)
    return stack.joinToString("")
}

fun partA(inp: String) = next(inp)
fun partB(inp: String) = next(next(inp))

fun main(){
    val inp = readln()
    println("Part A: ${partA(inp)}")
    println("Part B: ${partB(inp)}")
}
main()
