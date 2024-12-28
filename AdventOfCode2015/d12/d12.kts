sealed interface Expr
@JvmInline value class JsonNum(val v: Int) : Expr
@JvmInline value class JsonString(val v: String) : Expr
@JvmInline value class JsonList(val ls: List<Expr>) : Expr
@JvmInline value class JsonObj(val mp: Map<String, Expr>) : Expr

fun JsonObj.hasRed() = mp.any{(_, v) -> v is JsonString && v.v == "red"}

class Parser(val s: String) {
    var pos = 0

    fun peek() = s[pos]
    fun eat() = s[pos++]
    fun consume(pat: String) = Regex(pat).matchAt(s, pos)!!.also{pos = it.range.endExclusive}
    fun expr() = when(peek()) {
        '[' -> list()
        '{' -> obj()
        '"' -> string()
        else -> num()
    }
    fun num() = JsonNum(consume("-?[0-9]+").value.toInt())
    fun string() = JsonString(consume("\"([^\"]*)\"").groupValues[1])
    fun list(): JsonList {
        assert(eat() == '[')
        val ls = mutableListOf<Expr>()
        while(true) {
            ls.add(expr())
            if(peek() == ']')
                break
            assert(eat() == ',')
        }
        assert(eat() == ']')
        return JsonList(ls)
    }
    fun obj(): JsonObj {
        assert(eat() == '{')
        val mp = mutableMapOf<String, Expr>()
        while(true) {
            val key = string().v
            assert(eat() == ':')
            mp[key] = expr()
            if(peek() == '}')
                break
            assert(eat() == ',')
        }
        assert(eat() == '}')
        return JsonObj(mp)
    }
}

fun partA(inp: String): Int {
    fun sm(u: Expr): Int = when(u){
        is JsonString -> 0
        is JsonNum -> u.v
        is JsonList -> u.ls.sumOf{sm(it)}
        is JsonObj -> u.mp.map{(_, v) -> sm(v)}.sum()
    }
    return sm(Parser(inp).expr())
}

fun partB(inp: String): Int {
    val tree = Parser(inp).expr()
    fun sm(u: Expr): Int = when(u){
        is JsonString -> 0
        is JsonNum -> u.v
        is JsonList -> u.ls.sumOf{sm(it)}
        is JsonObj -> u.takeIf{!it.hasRed()}?.mp?.map{(_, v) -> sm(v)}?.sum() ?: 0
    }
    return sm(Parser(inp).expr())
}

fun main(){
    val raw = readln()
    println("Part A: ${partA(raw)}")
    println("Part B: ${partB(raw)}")
}
main()
