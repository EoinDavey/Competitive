import java.security.MessageDigest
import kotlin.experimental.and

fun solve(key: String, tgt: Int): Int {
    var i = 1
    while(true) {
        val msg = key + i.toString()
        val md = MessageDigest.getInstance("MD5")
        val dig = md.digest(msg.toByteArray())
        if(dig.take(tgt / 2).all{it == 0.toByte()} &&
            (tgt % 2 == 0 || (dig[tgt / 2].and(0xF0.toByte()) == 0.toByte()))){
            return i
        }
        i++
    }
}

fun main(){
    val key = readln()
    println("Part A: ${solve(key, 5)}")
    println("Part B: ${solve(key, 6)}")
}
main()
