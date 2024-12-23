fun sortedTrip(u: String, v: String, w: String): Triple<String, String, String> {
    val (a, b, c) = listOf(u, v, w).sorted()
    return Triple(a, b, c)
}

fun partA(adjList: Map<String, List<String>>): Int {
    val found = mutableSetOf<Triple<String, String, String>>()
    for((u, u_nbrs) in adjList) {
        for(v in u_nbrs) {
            adjList[v]?.forEach{w ->
                if(w in u_nbrs)
                    found.add(sortedTrip(u, v, w))
            }
        }
    }
    return found.filter{(u, v, w) -> u.startsWith('t') || v.startsWith('t') || w.startsWith('t')}.count()
}

fun isClique(vxs: List<String>, adjSet: Set<Pair<String, String>>): Boolean {
    for(i in 0..<vxs.size){
        for(j in 0..<i){
            if(Pair(vxs[i], vxs[j]) !in adjSet)
                return false
        }
    }
    return true
}

fun maxClique(vxs: List<String>, adjSet: Set<Pair<String, String>>): List<String> {
    assert(vxs.size <= 13)
    var bst = listOf<String>()
    for(st in 0..<(1 shl vxs.size)) {
        val elems = (0..<vxs.size).filter{(st and (1 shl it)) != 0}.map{vxs[it]}
        if(elems.size > bst.size && isClique(elems, adjSet))
            bst = elems
    }
    return bst
}

fun partB(adjList: Map<String, List<String>>, adjSet: Set<Pair<String, String>>): String {
    var bst = listOf<String>()
    for((u, u_nbrs) in adjList) {
        val subClique = maxClique(u_nbrs, adjSet)
        if(subClique.size + 1 > bst.size)
            bst = subClique + listOf(u)
    }
    return bst.sorted().joinToString(",")
}

fun main(){
    val lines = generateSequence(::readlnOrNull)
        .map{it.split("-")}
        .flatMap{(a, b) ->
            listOf(Pair(a, b), Pair(b, a))
        }
        .toList()
    val adjList = lines.groupBy({it.first}, {it.second})
    val adjSet = lines.toSet()
    println("Part A: ${partA(adjList)}")
    println("Part B: ${partB(adjList, adjSet)}")
}
main()
