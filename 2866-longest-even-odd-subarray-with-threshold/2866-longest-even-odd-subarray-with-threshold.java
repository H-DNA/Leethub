class Solution {
    public int longestAlternatingSubarray(int[] nums, int threshold) {
        int maxLen = 0;
        int curLen = 0;
        int curParity = 0;
        for (int num: nums) {
            if (curLen == 0 && num % 2 == 0 && num <= threshold) {
                curLen += 1;
                curParity = 0;
            } else if (curLen > 0 && curParity != num % 2 && num <= threshold) {
                curLen += 1;
                curParity = num % 2;
            } else {
                maxLen = Math.max(maxLen, curLen);
                curLen = (num % 2 == 0 && num <= threshold) ? 1 : 0;
                curParity = 0;
            }
        }
        return Math.max(maxLen, curLen);
    }
}