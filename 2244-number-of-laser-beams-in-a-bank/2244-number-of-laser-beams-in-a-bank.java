class Solution {
    public int numberOfBeams(String[] bank) {
        int res = 0;
        long prev = 0;

        for (final String str: bank) {
            final long cur = str.chars().filter(ch -> ch == '1').count();
            if (cur > 0) {
                res += prev * cur;
                prev = cur;
            }
        }

        return  (int) res;
    }
}