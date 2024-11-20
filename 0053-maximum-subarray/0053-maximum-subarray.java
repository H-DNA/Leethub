class Solution {
    public int maxSubArray(int[] nums) {
        int resSum = Integer.MIN_VALUE;
        int minSum = 0;
        int sum = 0;

        for (int i = 0; i < nums.length; ++i) {
            sum += nums[i];
            resSum = Math.max(resSum, sum - minSum);
            minSum = Math.min(sum, minSum);
        }

        return resSum;
    }
}