import java.util.*

fun readLn() = readLine()!! // string line
fun readInt() = readLn().toInt() // single int
fun readStrings() = readLn().split(" ") // list of strings
fun readInts() = readStrings().map { it.toInt() } // list of ints

fun f(a: Int, x: Int, y: Int): Int {
    if (x < 0 || y < 0 || x > a || y > a) {
        return 2;
    }

    if (x == 0 || y == 0 || x == a || y == a) {
        return 1;
    }

    return 0;
}

fun main() {
    val inp = readInts()

	val a = inp[0]
	val x = inp[1]
	val y = inp[2]
	
    println(f(a, x, y))
}