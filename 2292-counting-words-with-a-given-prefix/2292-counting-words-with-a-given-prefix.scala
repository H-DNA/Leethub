object Solution {
    def prefixCount(words: Array[String], pref: String): Int = {
        words.filter(_.startsWith(pref)).length
    }
}