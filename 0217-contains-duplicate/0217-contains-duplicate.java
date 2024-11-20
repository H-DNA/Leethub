class Solution {
    public boolean containsDuplicate(int[] nums) {
        if (nums.length == 0)
            return false;

        Arrays.sort(nums, 0, nums.length);

        int prevNumber = nums[0];
        for (int i = 1; i < nums.length; ++i)
            if (nums[i] == prevNumber)
                return true;
            else prevNumber = nums[i];
        
        return false;
    }
}